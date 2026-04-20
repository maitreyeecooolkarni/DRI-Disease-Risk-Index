#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

const int gaspin = 32;
const int LEDPIN = 2;

DHT dht(DHTPIN, DHTTYPE);


// STRUCT creation for sending into queue.
typedef struct
{
    float humid;
    float temp;
    int gasval;

} SensorData;


// QUEUE HANDLE
QueueHandle_t Queue1;

// TaskNotification HANDLE
TaskHandle_t alertTaskHandle;


// SENSOR TASK
void SensorTask(void *pvParameters)
{
    SensorData Data;

    while(1)
    {
        Data.humid = dht.readHumidity();
        Data.temp = dht.readTemperature();
        Data.gasval = analogRead(gaspin);

        Serial.println("Sending data to queue");

        xQueueSend(Queue1, &Data, portMAX_DELAY);

        vTaskDelay(pdMS_TO_TICKS(2000));

        if(Data.temp < 30 && Data.humid < 60)
        {
            xTaskNotifyGive(alertTaskHandle);
        }

        if(Data.gasval < 1000)
        {
            xTaskNotifyGive(alertTaskHandle);
        }
    }
}


// ALERT TASK
void AlertTask(void *pvParameters)
{
    while(1)
    {
        if(ulTaskNotifyTake(pdTRUE, portMAX_DELAY))
        {
            Serial.println("Temperature Alert");
            digitalWrite(LEDPIN, HIGH);
            Serial.println("Gas Alert");
        }
    }
}


// UART Task
void uartTask(void *pvParameters)
{
    SensorData Received;

    while(1)
    {
        if(xQueueReceive(Queue1, &Received, portMAX_DELAY))
        {
            Serial.print("Temp: ");
            Serial.println(Received.temp);

            Serial.print("Humidity: ");
            Serial.println(Received.humid);

            Serial.print("Gas: ");
            Serial.println(Received.gasval);

        }
         vTaskDelay(pdMS_TO_TICKS(2000));

    }
}


// SETUP
void setup()
{
    Serial.begin(9600);

    dht.begin();

    pinMode(LEDPIN, OUTPUT);
    pinMode(gaspin, INPUT);

    Queue1 = xQueueCreate(3, sizeof(SensorData));

    if(Queue1 == NULL)
    {
        Serial.println("Queue creation failed");
        while(1);
    }

    xTaskCreate(
        SensorTask,
        "SensorTask",
        2048,
        NULL,
        2,
        NULL
    );

    xTaskCreate(
        AlertTask,
        "AlertTask",
        2048,
        NULL,
        3,
        &alertTaskHandle   // FIXED: store task handle
    );

    xTaskCreate(
        uartTask,
        "uartTask",
        2048,
        NULL,
        2,
        NULL
    );
}


void loop()
{
}
