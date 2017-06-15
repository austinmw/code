var SerialPort = require('serialport');
var ON_DEATH = require('death');

// serial setup
var portName = '/dev/cu.usbserial-DA01LOA2',
portConfig = {
	baudRate: 9600,
	parser: SerialPort.parsers.readline("\n")
};
var sp;
sp = new SerialPort(portName, portConfig);


sp.on("open", function (err) {
	if (err) 
		return console.log('Error opening port: ', err.message);
	var on_signal = "1";
	console.log("\n\nSending ON signal to car.\n\n");
	for (var i = 0; i < 100; i++)
		sp.write(on_signal);
	// Cleanup when termination signals are sent to process
	ON_DEATH(function(signal, err) {
		var death_msg = "Q";
		for (var i = 0; i < 100; i++)
			sp.write(death_msg);
		sp.close();   
		console.log("\n\nSending OFF signal to car.\n\n")
		process.exit();
	})
}); 
