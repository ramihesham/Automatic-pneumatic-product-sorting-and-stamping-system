# 🏭 Automatic Product sorting and Stamping System

An automated pneumatic product stamping system that intelligently sorts and stamps products based on colour detection as they move along a conveyor belt combining **Arduino-based sensing**, **pneumatic actuation**, and **electro-pneumatic control**.

---

## Overview

In manufacturing, the final packaging step often requires stamping products with registration numbers, production dates, or expiry dates. This project automates that process by deploying a conveyor-belt system that:

1. **Detects product colour** using a colour sensor
2. **Routes blue products** directly into a storage box via a pneumatic piston (no stamping needed)
3. **Stamps red products** using a pneumatic linear piston triggered by an ultrasonic sensor
4. **Ejects stamped products** into a separate output box via pneumatic piston

---

## Features

- **Colour-based sorting** — automatically distinguishes between red and blue products
- **Ultrasonic detection** — triggers the stamp only when a product is in position
- **Double-acting pneumatic cylinders** — precise extend/retract control without spring dependency, suitable for upside-down stamping installation
- **5/2 DCV solenoid control** — relay-based signal routing from Arduino sensors to 24V solenoids
- **Fully automated loop** — products move continuously with no manual intervention

---

## Prototype
<img width="522" height="410" alt="prototype top view" src="https://github.com/user-attachments/assets/af743b6d-5459-40b5-bd5d-a854969280b5" />
```
```

## System Architecture

```
┌──────────────────────────────────────────────────────────────┐
│                     Conveyor Belt (DC Motor)                 │
│                                                              │
│  [Product] ──► Colour Sensor                                 │
│                    │                                         │
│           ┌────────┴────────┐                                │
│         BLUE              RED                                │
│           │                 │                                │
│     Piston A         Ultrasonic Sensor 1                     │
│  (push to Box 1)           │                                 │
│                      Stamping Piston B                       │
│                     (pnuematic stamper)                      │
│                            │                                 │
│                     Ultrasonic Sensor 2                      │
│                            │                                 │
│                        Piston C                              │
│                    (push to Box 2)                           │
└──────────────────────────────────────────────────────────────┘
```

---

## How It Works

### Step 1 — Colour Detection & Sorting (Blue Products)

The colour sensor reads the product on the belt. If **blue** is detected, relay R closes and energises solenoid S1, switching the DCV to extend **Cylinder A** and push the product into Box 1. When the piston reaches its limit (A1), solenoid S11 fires and retracts it back to A0.

### Step 2 — Stamping (Red Products)

If the product is **red**, the relay stays open and the product travels forward to the stamping station. **Ultrasonic Sensor 1 (relay B)** detects the product beneath the stamp arm. Solenoid S2 extends **Cylinder B** (the stamp) downward. Once fully extended (B1), solenoid S21 retracts it.

### Step 3 — Output Ejection

After stamping, **Ultrasonic Sensor 2 (relay L)** detects the finished product. Solenoid S3 extends **Cylinder C** to push the stamped product into Box 2. Switch C1 then fires solenoid S31 to retract it back to C0.

---

## Components

### Sensors & Electronics

| Component | Quantity | Purpose |
|---|---|---|
| Colour Sensor (TCS3200) | 1 | Detect red vs. blue products |
| Ultrasonic Sensor (HC-SR04) | 2 | Detect product position at stamping & ejection stations |
| Arduino UNO | 1+ | Read sensors and control relays |
| Relay Module | Multiple | Interface 5V Arduino signals to 24V solenoids |
| 24V DC Power Supply | 1 | Power the solenoids |

### Hydraulic & Mechanical

| Component | Quantity | Purpose |
|---|---|---|
| Double-Acting Cylinders | 3 | Sort (A), Stamp (B), Eject (C) |
| 5/2 Directional Control Valve (DCV) | 3 | Control cylinder extension/retraction |
| Solenoid Valves (24V DC) | 6 | Electrically actuate DCVs (S1/S11, S2/S21, S3/S31) |
| Silencers | Connected to DCV ports 3 & 5 | Reduce pressure pulsation and noise |
| DC Motors | 2 | Drive the conveyor belt |
| Bearings & Shafts | — | Support smooth belt rotation |

---

## pneumatic Circuit — Fluid Sim

The full system was designed and validated in **Fluid Sim** before physical assembly.

<img width="572" height="291" alt="system on fluidsim" src="https://github.com/user-attachments/assets/e68e413d-4f01-4461-b1fe-e3832e80893a" />


### DCV Port Connections (5/2 Valve @ 24V DC)

| Port | Connected To |
|---|---|
| Port 1 | Air compressor |
| Port 2 | Cylinder (extend side) |
| Port 4 | Cylinder (retract side) |
| Port 3 | Silencer |
| Port 5 | Silencer |

---
