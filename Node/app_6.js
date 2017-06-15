/*

EC544 group 4
Challenge Six 
Read values from XBee
And locate object on map

*/

/* -------- Declare Dependices --------- */


var SerialPort = require('serialport');
var express = require('express');
app = express();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var ON_DEATH = require('death');
var PythonShell = require('python-shell');
var xbee_api = require('xbee-api');

app.get('/', function(req, res){
  res.sendFile('/Users/jmeunier28/Desktop/EC544/challenges/EC544/challengeSix/public/nearBy.html');
});

app.use(express.static(__dirname + '/public'));


/* ------------ Error Handling ---------------*/

//catch 404 and forward to error handler
app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

// error handlers

// development error handler
// will print stacktrace
if (app.get('env') === 'development') {
  app.use(function(err, req, res, next) {
    res.status(err.status || 500);
    res.render('error', {
      message: err.message,
      error: err
    });
  });
}

// production error handler
// no stacktraces leaked to user
app.use(function(err, req, res, next) {
  res.status(err.status || 500);
  res.render('error', {
    message: err.message,
    error: {}
  });
});

/* -----Run App on LocalHost Port 3000----- */

http.listen(3000, function(){
  console.log('listening on *:3000');
});

/* -----Configure Xbee and serial port----- */

var C = xbee_api.constants;
var XBeeAPI = new xbee_api.XBeeAPI({
  api_mode: 2
});

var portName = '/dev/cu.usbserial-AD01SSII';
var sampleDelay = 3000;


//Note that with the XBeeAPI parser, the serialport's "data" event will not fire when messages are received!
portConfig = {
	baudRate: 9600,
  parser: XBeeAPI.rawParser()
};

var sp;
sp = new SerialPort.SerialPort(portName, portConfig);

var RSSIRequestPacket = {
  type: C.FRAME_TYPE.ZIGBEE_TRANSMIT_REQUEST,
  destination64: "000000000000ffff",
  broadcastRadius: 0x01,
  options: 0x00,
  data: "test"
}

var requestRSSI = function(){
  sp.write(XBeeAPI.buildFrame(RSSIRequestPacket));
}

/* -------- App Logic ----------*/

var numSamples = 3;

console.log(' Running till each beacon gets at least', numSamples ,'rssi values to average.')

// variables
var sampleDelay = 2000;
var r1 = [];
var r2 = [];
var r3 = [];
var r4 = [];
var finalPoints = [];
r1Arr = [];
r2Arr = [];
r3Arr = [];
r4Arr = [];
options = {
	pythonOptions: ['-W', 'ignore'], //for supressing warnings
	scriptPath: '/Users/jmeunier28/Desktop/EC544/challenges/EC544/challengeSix',
	args: [44.2, 59.1, 88.3, 100.9]
};


sp.on("open", function () {
	// start main function, set interval
	requestRSSI();
	setInterval(requestRSSI, sampleDelay);
	// input
	console.log("opened serialport");
	io.on("connection",function(socket){
		console.log("user connection");
	XBeeAPI.on("frame_object", function(frame) {
		if (frame.type == 144){
			// split input, sample number
			var beaconID = frame.data[1];
			var rssiVal = frame.data[0];
			// check if finished data collection	
			if ((r1.length >= numSamples) && (r2.length >= numSamples) && 
			    (r3.length >= numSamples) && (r4.length >= numSamples))
			{
			//if (r4.length >= numSamples) { // for testing, use above with all 4 beacons
				// Average each of the four beacons' values
				var r1avg = 0;
				for (var i = 0; i < r1.length; i++)
					r1avg += r1[i];
				r1avg /= r1.length;
				finalPoints.push(r1avg);
				r1Arr.push(r1avg);
				var r2avg = 0;
				for (var i = 0; i < r2.length; i++)
					r2avg += r2[i];
				r2avg /= r2.length;
				finalPoints.push(r2avg);
				r2Arr.push(r2avg);
				var r3avg = 0;
				for (var i = 0; i < r3.length; i++)
					r3avg += r3[i];
				r3avg /= r3.length;
				finalPoints.push(r3avg);
				r3Arr.push(r3avg);
				var r4avg = 0;
				for (var i = 0; i < r4.length; i++)
					r4avg += r4[i];
				r4avg /= r4.length;
				finalPoints.push(r4avg);
				r4Arr.push(r4avg);
				// add cluster number to end for matlab code
				//finalPoints.push(binNum);
				// print		
				console.log('\nTraining point values and bin: ' + r1Arr[r1Arr.length-1] + r2Arr[r2Arr.length-1] + r3Arr[r2Arr.length-1] + r4Arr[r2Arr.length-1])
				
				options['args'][0] = r1Arr[r1Arr.length-1];
				options['args'][1] = r2Arr[r2Arr.length-1];
				options['args'][2] = r3Arr[r3Arr.length-1];
				options['args'][3] = r4Arr[r4Arr.length-1];
				console.log("\nOptions are: " + options['args']);
				PythonShell.run('classifier.py',options,function(err, results){
					console.log("Calling python classifier");
					console.log("\nPoint is: \n" + options['args']);
					if (err) throw err;

					console.log("I am in bin: " + results);
					
  
						console.log('a user connected');
						socket.emit('binNumber', results);
			
					
					
					r1 = [];
					r2 = [];
					r3 = [];
					r4 = [];

				});
				
			}
			// populate beacon arrays up to sample number, error check, print data and totals
			else if ((rssiVal != 0) && (rssiVal != 255))
			{
				//console.log("  Beacon ID: " + beaconID + ", RSSI: " + rssiVal);
				//console.log('   Pushing value to beacon #', beaconID)
				console.log(r1Arr);
				if (beaconID == 1){
				r1.push(rssiVal);
				}
				else if(beaconID == 2){
				r2.push(rssiVal);
				}
				else if(beaconID == 3){
				r3.push(rssiVal);
				}
				else if(beaconID == 4){
				r4.push(rssiVal);
				}
				console.log("Totals::  r1:", r1.length, "  r2:", r2.length, "  r3:", r3.length, "  r4:", r4.length);
			}

		}

		// 	options['args'][0] = r1Arr[r1Arr.length-1];
		// 	options['args'][1] = r2Arr[r2Arr.length-1];
		// 	options['args'][2] = r3Arr[r3Arr.length-1];
		// 	options['args'][3] = r4Arr[r4Arr.length-1];
		// 	console.log("Outside the interval: " + options['args']);

		// var i = 0;
		// var classify = function()
		// {

		// 	console.log("In interval function")
		// 	console.log("options are: " + options['args']);

		// 	PythonShell.run('classifier.py',options,function(err, results){
		// 		console.log("Calling python classifier");
		// 		console.log("\nPoint is: \n" + options['args']);
		// 		if (err) throw err;

		// 		console.log("I am in bin: " + results);

		// 	});
		// 	i +=1;
		// 	if(i === 5) clearInterval(timer);

		// 	// pyshell = new PythonShell('classifier.py', options);
		// 	// // // pyshell.end(function (err) {
		// 	// // // 	if (err) throw err;
		// 	// // // 	console.log('finished');
		// 	// // // });
		// 	// pyshell.on('message', function (message) 
		// 	// {
		// 	// 	console.log("Calling python classifier");
		// 	// 	console.log("\nPoint is: \n" + options['args']);
		// 	// 	//if (err) throw err;
		// 	// 	// results is an array consisting of messages collected during execution
		// 	// 	//console.log('results: %j', results);
		// 	// 	console.log("\nI think i'm in bin: " + message);
		// 	// 	//socket.emit('left', results);
		// 	// }); // end python call 

		// 	// pyshell.end(function (err) {
		// 	// 	if (err) throw err;
		// 	// 	console.log('finished');
		// 	// });

		// }

		// var timer = setInterval(classify, 1*10000); // call every 10 seconds

	}); // end Xbee conn
}); //end io conn
}); // end serial port conn



