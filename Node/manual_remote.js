var SerialPort = require('serialport');
var ON_DEATH = require('death');
const readline = require('readline');

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
	
	console.log("      Controls")
	console.log("---------------------")
	console.log("q: send off signal to car and quit")
	console.log("t: toggle auto/manual")
	console.log("s: stop car")
	console.log("up arrow: increase speed")
	console.log("down arrow: decrease speed")
	console.log("left arrow: increase left turn")
	console.log("right arrow: increase right turn")
	console.log("space: center wheels\n")	
	
	var send_msg = ''
	const readline = require('readline');
	readline.emitKeypressEvents(process.stdin);
	process.stdin.setRawMode(true);
	process.stdin.on('keypress', (str, key) => {

		// quit signal
		if (key.name === 'q') {
			send_msg = 'Q';
			for (var i = 0; i < 100; i++)
				sp.write(send_msg);
			sp.close();   
			console.log("\nSending OFF signal to car.\n\n")
			process.exit();
		} 
		
		// all other signals
		
		else if (key.name == 't') {
			send_msg = 'T';
			sp.write(send_msg);
			console.log("Toggling auto/manual controls.")
		}
		else if (key.name == 'up') {
			send_msg = 'U';
			
			sp.write(send_msg);
			console.log("Increasing speed.")
		}
		else if (key.name == 'down') {
			send_msg = 'D';
			sp.write(send_msg);
			console.log("Decreasing speed.")
		}
		else if (key.name == 'c') {
			send_msg = 'C';
			sp.write(send_msg);
			console.log("Centering wheels.")
		}
		else if (key.name == 'space') {
			send_msg = 'S';
			sp.write(send_msg);
			console.log("Toggle stopping/starting car.")
		}				
		else if (key.name == 'left') {
			send_msg = '<';
			sp.write(send_msg);
			console.log("Turning left.")
		}		
		else if (key.name == 'right') {
			send_msg = '>';
			sp.write(send_msg);
			console.log("Turning right.")
		}		
		
		else {
			console.log()
			console.log(`You pressed the "${str}" key`);
			console.log("Not a valid selection.\n")
			//console.log();
			//console.log(key);
			//console.log();
		}
	});
	console.log('Press any key...\n');
	

}); 
