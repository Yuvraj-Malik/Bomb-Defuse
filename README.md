# 💣 Bomb Diffuse Game (Arduino Project)

A simple yet thrilling **Arduino-based Bomb Diffusing Game**, where players must **observe LED blinking patterns** and **cut (or press) the correct wire/button** corresponding to the LED that blinked the most — before the timer runs out!

---

## 🚀 Overview

This game simulates a **bomb-defusing scenario** where:

- 4 LEDs represent different wires.
- LEDs blink in random sequences.
- Players must **memorize which LED blinked the most**.
- To diffuse the bomb, the player must **select the correct wire/button** within 5 seconds.
- A **buzzer** signals success or failure.

If you pick the wrong LED or run out of time — 💥 _the bomb "explodes"!_

---

## 🧠 How It Works

1. **Game starts** – LEDs blink in random order for a few seconds.
2. **Observe carefully** – One LED will blink more times than the others.
3. **Make your move** – Press or trigger the input corresponding to the LED that blinked most frequently.
4. **Win or lose!**
   - ✅ Correct choice → Victory tone plays.
   - ❌ Wrong choice / Timeout → Failure tone plays.

---

## ⚙️ Hardware Requirements

| Component                        | Quantity | Description                         |
| -------------------------------- | -------- | ----------------------------------- |
| Arduino UNO / Nano               | 1        | Main controller board               |
| LEDs                             | 4        | Represent different wires           |
| 220Ω Resistors                   | 4        | Current limiting resistors for LEDs |
| Push Buttons or Detachable Wires | 4        | Inputs to simulate wire cutting     |
| Buzzer                           | 1        | For success/failure tones           |
| Jumper Wires                     | -        | For connections                     |
| Breadboard                       | 1        | For prototyping                     |

---

## 🧩 Pin Connections

| Component          | Arduino Pin | Type                        |
| ------------------ | ----------- | --------------------------- |
| LED 1–4            | 2, 3, 4, 5  | Output                      |
| Button/Wire Inputs | 6, 7, 8, 9  | Input (with `INPUT_PULLUP`) |
| Buzzer             | 10          | Output                      |

---

## 💾 Code Explanation

### 🔸 Setup Phase

Initializes serial communication, sets pin modes, and prints the game start message.

### 🔸 LED Blinking Phase

Randomly selects LEDs to blink (`blinkLED()`), tracking the number of times each LED blinks.

### 🔸 Player Input Phase

Waits up to **5 seconds** for the player to select a wire/button. The input is checked via `checkAnswer()`.

### 🔸 Feedback Phase

Plays a **success tone** if correct or a **failure tone** if wrong or timed out.

---

## 🎵 Sound Effects

| Event      | Tone Behavior                                          |
| ---------- | ------------------------------------------------------ |
| ✅ Success | Two rising tones (1000Hz → 1500Hz)                     |
| ❌ Failure | Alternating low tones (400Hz ↔ 200Hz) repeated 3 times |

---

## 🧠 Key Functions

| Function                       | Description                                   |
| ------------------------------ | --------------------------------------------- |
| `blinkLED(int index)`          | Blinks a given LED briefly                    |
| `checkAnswer(int chosenIndex)` | Compares user’s choice with most-frequent LED |
| `playSuccessTone()`            | Plays victory tone sequence                   |
| `playFailTone()`               | Plays failure tone sequence                   |

---

## 🕹️ How to Play

1. Upload the code to your Arduino board.
2. Observe the LED blinking pattern.
3. Identify the LED that blinked most often.
4. Press the corresponding button or detach that wire within 5 seconds.
5. Listen for the buzzer to know if you succeeded or failed.

---

## 🧰 Tools Used

- **Arduino IDE**
- **C/C++ (Arduino language)**
- **Serial Monitor (for feedback)**

---
