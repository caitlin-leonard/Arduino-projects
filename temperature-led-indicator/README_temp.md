<h2 align="center">Temperature LED Indicator</h2>
<p align="center">
  Visual temperature indicator using a TMP sensor and three LEDs —
  more LEDs light up as temperature rises above baseline.
</p>

<hr>

<h3>🌡️ Overview</h3>
<p>
A TMP temperature sensor on pin A0 reads ambient temperature.
The ADC value is converted to voltage and then to degrees Celsius.
Three LEDs on pins 2, 3, and 4 light up progressively based on how far
the temperature is above a baseline of 25°C.
All readings are printed to the Serial Monitor in real time.
</p>

<hr>

<h3>⚙️ How It Works</h3>
<pre><code>ADC (0–1023) → voltage = (ADC / 1024.0) × 5.0
temperature  = (voltage - 0.5) × 100   (TMP sensor formula)

&lt; 27°C  → all LEDs off
≥ 27°C  → LED 1 on  (pin 2)
≥ 29°C  → LED 1 + 2 on  (pins 2, 3)
≥ 31°C  → all 3 LEDs on  (pins 2, 3, 4)
</code></pre>

<hr>

<h3>🔌 Pin Connections</h3>
<table>
  <tr><th>Component</th><th>Pin</th></tr>
  <tr><td>TMP sensor</td><td>A0</td></tr>
  <tr><td>LED 1</td><td>2</td></tr>
  <tr><td>LED 2</td><td>3</td></tr>
  <tr><td>LED 3</td><td>4</td></tr>
</table>

<hr>

<h3>📟 Serial Monitor Output</h3>
<pre><code>sensor value: 153, volts: 0.75, degrees C: 25.00
sensor value: 163, volts: 0.80, degrees C: 29.30
</code></pre>

<hr>

<h3>▶️ How to Run</h3>
<ol>
  <li>Wire components as per pin table above</li>
  <li>Upload <code>temp_led.ino</code> to Arduino Uno</li>
  <li>Open Serial Monitor at 9600 baud to see live readings</li>
  <li>Apply heat to the sensor to see LEDs light up!</li>
</ol>
