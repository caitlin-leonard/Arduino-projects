<h2 align="center">RGB LED Mixer</h2>
<p align="center">
  Control an RGB LED's colour in real time using three potentiometers —
  one for each colour channel (Red, Green, Blue).
</p>

<hr>

<p align="center">
  <img src="rgb.gif" width="600"/>
</p>

<hr>

<h3>💡 Overview</h3>
<p>
Three potentiometers are read via analog pins A0, A1, and A2.
The raw ADC values (0–1023) are scaled down to the PWM range (0–255)
and written to the RGB LED pins using <code>analogWrite()</code>,
producing any colour mix in real time.
Raw and mapped values are also printed to the Serial Monitor.
</p>

<hr>

<h3>⚙️ How It Works</h3>
<pre><code>Potentiometer → analogRead() → 0 to 1023
Divide by 4   → 0 to 255  (PWM range)
analogWrite() → LED brightness per channel
</code></pre>

<hr>

<h3>🔌 Pin Connections</h3>
<table>
  <tr><th>Component</th><th>Pin</th></tr>
  <tr><td>Red potentiometer</td><td>A0</td></tr>
  <tr><td>Green potentiometer</td><td>A1</td></tr>
  <tr><td>Blue potentiometer</td><td>A2</td></tr>
  <tr><td>Red LED</td><td>10 (PWM)</td></tr>
  <tr><td>Green LED</td><td>9 (PWM)</td></tr>
  <tr><td>Blue LED</td><td>11 (PWM)</td></tr>
</table>

<hr>

<h3>📟 Serial Monitor Output</h3>
<pre><code>Raw Sensor Values    red: 512   green: 256   blue: 800
Mapped Sensor Values red: 128   green: 64    blue: 200
</code></pre>

<hr>

<h3>▶️ How to Run</h3>
<ol>
  <li>Wire components as per pin table above</li>
  <li>Upload <code>rgb_mixer.ino</code> to Arduino Uno</li>
  <li>Open Serial Monitor at 9600 baud</li>
  <li>Turn the potentiometers to mix colours!</li>
</ol>
