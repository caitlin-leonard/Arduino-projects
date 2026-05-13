<h2 align="center">Button LED Controller</h2>
<p align="center">
  Control three LEDs using a push button — one LED on when idle,
  two LEDs alternating when the button is pressed.
</p>
<hr>
<p align="center">
  <img src="button_led.gif" width="600"/>
</p>
<hr>
<h3>💡 Overview</h3>
<p>
A push button on pin 2 controls the behaviour of three LEDs on pins 3, 4, and 5.
When the button is not pressed, one LED stays on. When pressed, two LEDs alternate
on and off with a 1-second delay each.
</p>
<hr>
<h3>⚙️ How It Works</h3>
<pre><code>Button NOT pressed → pin 3 HIGH (LED 1 on, others off)
Button pressed     → pin 5 HIGH for 1s → pin 4 HIGH for 1s (alternating)
</code></pre>
<hr>
<h3>🔌 Pin Connections</h3>
<table>
  <tr><th>Component</th><th>Pin</th></tr>
  <tr><td>Push button</td><td>2</td></tr>
  <tr><td>LED 1</td><td>3</td></tr>
  <tr><td>LED 2</td><td>4</td></tr>
  <tr><td>LED 3</td><td>5</td></tr>
</table>
<hr>
<h3>▶️ How to Run</h3>
<ol>
  <li>Wire components as per pin table above</li>
  <li>Upload <code>button_led.ino</code> to Arduino Uno</li>
  <li>Press the button to see LEDs alternate!</li>
</ol>
