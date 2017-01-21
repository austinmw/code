/*

EC544 group 4

Challenge Three

Remote Access

*/

/* -------- Declare Dependices --------- */


var SerialPort = require('serialport');
var express = require('express');
app = express();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var ON_DEATH = require('death');

app.get('/', function(req, res){
  res.sendFile('/Users/jmeunier28/Desktop/EC544/challenges/EC544/challengeThree/public/button.html');
});

app.use(express.static(__dirname + '/public'));

/* ----- Configure Serial Port -------- */

var portName = '/dev/cu.usbserial-AD01SSII',
portConfig = {
	baudRate: 9600,
};

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


/* -------- App Logic ----------*/

var sp;
sp = new SerialPort.SerialPort(portName, portConfig);
sp.on("open", function (err) {	
	var buffer;
	var num = 0;
	var count = 0;
	str = "";
	red = false;
	blue = false;
	green = false;
	kill = false;

	// Turn on
	console.log("Sending LED on signal.");
	console.log("Ctrl+C to quit and send LED off signal.");


		/*sp.on('data',function(data){ //grab data from XBee 
			buffer = String(data).split('\n');
			//console.log(buffer[0]);
			if (buffer[0] === "Red is ON"){
				red = true;
				blue = false;
				green = false;
				kill = false;
				str = buffer[0];
			}
			if (buffer[0] === "Green is ON"){
				green = true;
				blue = false;
				red = false;
				kill = false;
				str = buffer[0];
			}
			if (buffer[0] === "Blue is ON"){
				blue = true;
				red = false;
				green = false;
				kill = false;
				str = buffer[0];
			}
			if (buffer[0] === "LEDs are OFF"){
				kill = true;
				red = false;
				green = false;
				blue = false;
				str = buffer[0];
			}

		}); //end data conn*/

		io.on("connection",function(socket){
		
	  
		console.log('a user connected');


		  socket.on('redbuttonPress',function(string){
		  		console.log("Red Button Press");
		  		count +=1;
		  		//var str = "Red is ON";
		  		//socket.emit('msg', str);
				sp.write('1'); //red button pressed write 1 
				console.log(num);
				console.log(count);
				if (num != count){
					str = "Connection Error Cant Read LED Status";
					socket.emit('msg', str);
				}
				}); //end red

		  socket.on('greenbuttonPress',function(string){
		  		console.log("Green Button Press");
		  		count +=1;
		  		//var str = "Green is ON";
		  		//socket.emit('msg', str);
				sp.write('2'); //green button pressed write 1 
				console.log(num);
				console.log(count);
				if (num != count){
					str = "Connection Error Cant Read LED Status";
					socket.emit('msg', str);
				}
				}); // end green

		  socket.on('bluebuttonPress',function(string){
		  		console.log("Blue Button Press");
		  		count +=1;
		  		//var str = "Blue is ON";
		  		//socket.emit('msg', str);
				sp.write('3'); //blue button pressed write 1 
				console.log(num);
				console.log(count);
				if (num != count){
					str = "Connection Error Cant Read LED Status";
					socket.emit('msg', str);
				}
				}); // end blue


		  socket.on('killbuttonPress',function(string){
		  		console.log("Kill Button Press");
		  		count +=1;
		  		//var str = "LED is OFF";
		  		//socket.emit('msg', str);
		  		sp.write('Q');
				console.log(num);
				console.log(count);
				if (num != count){
					str = "Connection Error Cant Read LED Status";
					socket.emit('msg', str);
				}
				// Turn off on program exit
				/*ON_DEATH(function(signal, err) {
					var death_msg = 'Q';
					sp.write(death_msg);
					sp.close();   
					console.log("\n\nSending reset signal to nodes.\n\n")
					process.exit();
				}); //end ondeath */
			}); // end kill button

		sp.on('data',function(data){ //grab data from XBee 
			buffer = String(data).split('\n');
			var num = 0;
			console.log(buffer[0]);
			if (buffer[0] === "R"){
				red = true;
				blue = false;
				green = false;
				kill = false;
				str = "Red is ON";
			}
			if (buffer[0] === "G"){
				green = true;
				blue = false;
				red = false;
				kill = false;
				str = "Green is ON";
			}
			if (buffer[0] === "B"){
				blue = true;
				red = false;
				green = false;
				kill = false;
				str = "Blue is ON";
			}
			if (buffer[0] === "F"){
				kill = true;
				red = false;
				green = false;
				blue = false;
				str = "LEDs are OFF";
			}

		if(red){
  			str = "Red is ON";
  		}
  		else if(green){
  			str = "Green is ON";
  		}
  		else if(blue){
  			str = "Blue is ON";
  		}
  		else if(kill){
  			str = "LEDs are OFF"
  		}
  		else{
  			str = "Connection Error Cant Read LED Status";
  		}
  		num +=1;

  		socket.emit('msg', str);

		}); //end data conn


		
			
	}); //end io conn
}); // end open serial port

