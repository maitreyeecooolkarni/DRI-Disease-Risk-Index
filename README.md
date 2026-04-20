# Dumpyard Risk Index (DRI) Monitoring System

## Overview

The **Dumpyard Risk Index (DRI) Monitoring System** is an IoT-based environmental monitoring solution designed to assess safety risks in landfill and dumpyard environments.

Dumpyards generate hazardous gases, stagnant water, and unsafe environmental conditions that can lead to:

- Vector-borne diseases
- Fire hazards
- Toxic gas exposure
- Water contamination risks

This system continuously monitors environmental parameters and calculates a **Dumpyard Risk Index (DRI)** to support early detection and preventive municipal action.

---

## Problem Statement

Municipal dumpyards are typically monitored manually and infrequently, making it difficult to detect unsafe environmental conditions in real time.

There is a need for a **continuous monitoring system** that:

- Detects environmental risk factors
- Converts sensor readings into meaningful risk levels
- Transmits data remotely
- Enables early warning alerts for authorities

This project addresses that need using embedded systems and IoT-based monitoring architecture.

---

## Proposed Solution

The system monitors multiple environmental parameters and calculates a **Dumpyard Risk Index (DRI)** based on sensor readings.

Measured parameters include:

- Temperature and humidity
- Harmful gas presence
- Water stagnation level
- Turbidity (water contamination indicator)

Based on sensor values, the system classifies dumpyard conditions into:

- LOW RISK
- MEDIUM RISK
- HIGH RISK

The processed data is transmitted wirelessly to a monitoring dashboard for visualization.

---

## System Architecture

System workflow:

Sensors → Microcontroller → DRI Calculation Logic → LoRa Communication → Node-RED Dashboard

---

## Hardware Components Used

- ESP32 / STM32 microcontroller
- DHT11 temperature and humidity sensor
- Gas sensor
- Ultrasonic sensor (stagnant water detection)
- Turbidity sensor
- LoRa communication module

---

## Software and Tools Used

- Embedded C / Arduino framework
- Node-RED dashboard
- LoRa communication interface
- Sensor calibration using Node-RED
- RTOS-based task structuring (concept implementation)

---

## Dumpyard Risk Index (DRI) Logic

The **DRI value** is calculated using environmental sensor inputs that represent potential dumpyard hazards.

Example contributors:

- Increased gas concentration → higher fire/toxic exposure risk
- Increased humidity → supports microbial growth
- Stagnant water presence → mosquito breeding risk
- High turbidity → indicates contaminated water accumulation

These parameters are combined to generate a final **risk level classification**.

---

## Features

- Real-time environmental monitoring
- Stagnant water detection using timer-based logic
- Risk classification using Dumpyard Risk Index (DRI)
- Long-range wireless communication using LoRa
- Dashboard visualization using Node-RED
- Modular and scalable system architecture

