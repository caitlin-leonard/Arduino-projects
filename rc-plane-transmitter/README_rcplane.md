<h2 align="center">RC Plane Transmitter</h2>
<p align="center">
  Arduino-based RC plane transmitter controlling ailerons, rudder, and throttle
  via servos, a stepper motor, joystick, and I2C LCD display.
</p>
<p align="center">
  <a href="https://wokwi.com/projects/404371170962619393">▶️ Try it on Wokwi Simulator</a>
</p>

<hr>

<h3>🛩️ Overview</h3>
<p>
This project implements a transmitter-side controller for an RC plane using an Arduino Uno.
It reads analog inputs from potentiometers and a joystick to control three servo motors
(left aileron, right aileron, rudder) and a stepper motor (throttle/propeller speed).
All live values are displayed on a 16×2 I2C LCD.
</p>

<hr>

<h3>⚙️ Features</h3>
<ul>
  <li>3 servo motors — left aileron, right aileron, rudder</li>
  <li>Stepper motor (A4988 driver) for throttle control via joystick</li>
  <li>Smooth acceleration/deceleration using <b>AccelStepper</b> library</li>
  <li>Toggle button to switch LCD display between left and right aileron angles</li>
  <li>Double-check <b>debouncing mechanism</b> for reliable button detection</li>
  <li><b>Emergency stop</b> button — halts stepper and locks system</li>
  <li>LCD updates only when values change — no flickering</li>
  <li>Joystick deadzone (threshold = 100) to prevent drift</li>
</ul>

<hr>

<h3>🔌 Pin Connections</h3>

<table>
  <tr><th>Component</th><th>Pin</th></tr>
  <tr><td>Stepper STEP</td><td>10</td></tr>
  <tr><td>Stepper DIR</td><td>11</td></tr>
  <tr><td>Stepper ENABLE</td><td>13</td></tr>
  <tr><td>Left Aileron Servo</td><td>2</td></tr>
  <tr><td>Right Aileron Servo</td><td>3</td></tr>
  <tr><td>Rudder Servo</td><td>4</td></tr>
  <tr><td>Joystick X</td><td>A2</td></tr>
  <tr><td>Joystick Y (throttle)</td><td>A3</td></tr>
  <tr><td>Toggle Button</td><td>5</td></tr>
  <tr><td>Emergency Stop Button</td><td>6</td></tr>
  <tr><td>LCD SDA/SCL</td><td>I2C (A4/A5)</td></tr>
</table>

<hr>

<h3>📟 LCD Display</h3>
<pre><code>Row 1: AL: [angle]          ← left aileron (or right, toggle)
Row 2: Rud: [angle]  Spd: [rpm]
</code></pre>
<p>Press the toggle button to switch between displaying left and right aileron angles on row 1.</p>
<p>Emergency stop displays:</p>
<pre><code>Row 1: EMERGENCY STOP
</code></pre>

<hr>

<h3>🖼️ Prototype</h3>
<p align="center">
  <img src="photo.png" width="600"/>
</p>

<hr>

<h3>🔗 Simulation</h3>
<p>
  Try the full circuit on Wokwi (no hardware needed):<br>
  <a href="https://wokwi.com/projects/404371170962619393">https://wokwi.com/projects/404371170962619393</a>
</p>

<hr>

<h3>📚 Libraries</h3>
<ul>
  <li><code>Servo.h</code> — servo motor control</li>
  <li><code>Wire.h</code> — I2C communication</li>
  <li><code>LiquidCrystal_I2C.h</code> — LCD display</li>
  <li><code>AccelStepper.h</code> — stepper motor with acceleration</li>
</ul>

<hr>

<h3>▶️ How to Run</h3>
<ol>
  <li>Install libraries via Arduino IDE Library Manager: <code>LiquidCrystal I2C</code>, <code>AccelStepper</code></li>
  <li>Wire components as per pin table above</li>
  <li>Upload <code>rc_plane.ino</code> to Arduino Uno</li>
  <li>Open Serial Monitor at 9600 baud to see stepper position</li>
  <li>Or simulate directly on <a href="https://wokwi.com/projects/404371170962619393">Wokwi</a></li>
</ol>
