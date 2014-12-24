var readline = require('readline');

var rl = readline.createInterface(process.stdin, process.stdout);


rl.question("What is your favourite food?", function(answer){
		console.log("your answer was " + answer);
});

rl.question("What is your color?", function(answer) {
	console.log("You answered" + answer);
	rl.close();
});

