<h2 align="center">🔧 Arduino Projects</h2>
<p align="center">
  A collection of Arduino projects built as part of coursework at IIITDM Kancheepuram —
  covering servo control, stepper motors, sensor interfacing, PWM, and I2C communication.
</p>

<hr>

<h3>📁 Projects</h3>

<table>
  <tr>
    <th>#</th>
    <th>Project</th>
    <th>Description</th>
    <th>Key Components</th>
  </tr>
  <tr>
    <td>1</td>
    <td><a href="rc-plane-transmitter/"><b>RC Plane Transmitter</b></a></td>
    <td>Transmitter-side controller for an RC plane — controls ailerons, rudder, and throttle via joystick and potentiometers, with emergency stop and live LCD display</td>
    <td>3× Servo, AccelStepper, A4988 driver, I2C LCD, joystick</td>
  </tr>
  <tr>
    <td>2</td>
    <td><a href="button-led-controller/"><b>Button LED Controller</b></a></td>
    <td>Push button switches between LED states — one LED on at idle, two LEDs alternating when pressed</td>
    <td>Push button, 3× LED</td>
  </tr>
  <tr>
    <td>3</td>
    <td><a href="temperature-led-indicator/"><b>Temperature LED Indicator</b></a></td>
    <td>Reads ambient temperature from a TMP sensor and lights up LEDs progressively as temperature rises above baseline</td>
    <td>TMP sensor, 3× LED, Serial Monitor</td>
  </tr>
  <tr>
    <td>4</td>
    <td><a href="rgb-led-mixer/"><b>RGB LED Mixer</b></a></td>
    <td>Three potentiometers independently control the Red, Green, and Blue channels of an RGB LED via PWM</td>
    <td>3× potentiometer, RGB LED, PWM</td>
  </tr>
</table>

<hr>

<h3>🗂️ Repository Structure</h3>
<pre><code>arduino-projects/
├── rc-plane-transmitter/
│   ├── rc_plane.ino
│   ├── photo.png
│   └── README.md
├── button-led-controller/
│   ├── button_led.ino
│   ├── button_led.gif
│   └── README.md
├── temperature-led-indicator/
│   ├── temp_led.ino
│   └── README.md
├── rgb-led-mixer/
│   ├── rgb_mixer.ino
│   └── README.md
└── README.md
</code></pre>

<hr>

<h3>🛠️ Tools & Setup</h3>
<ul>
  <li>Arduino Uno</li>
  <li>Arduino IDE — <a href="https://www.arduino.cc/en/software">download here</a></li>
  <li><a href="https://wokwi.com/projects/404371170962619393">Wokwi Simulator</a> — try the RC plane project without any hardware</li>
</ul>

<hr>

<h3>🏫 About</h3>
<p>
  Built as part of coursework at the<br>
  <b>Indian Institute of Information Technology, Design and Manufacturing (IIITDM), Kancheepuram</b>
</p>
