//Testing Games

//For input:
var readline = require('readline');

//Order of operations:
///1. Ask for number of players
///2. Random or Standard ELO (1200)
///3. Tourny Style or Round Robin
///4. Print out all statistics to screen


//Constructor for a basic player
var Player = function(name, ELO){
	this.name = name;
	this.ELO = ELO;
	this.numWins = 0;
	this.numLosses = 0;
	// NULL -> INT
	//Calculates the win/loss ratio
	ratioWL = function(){
		//Check for zero
		if(this.numWins + this.numLosses != 0){
			return this.numWins / (this.numLosses + this.numWins);
		}
		else {
			return 0;
		}
	}
}

//Ask for number of players
var numPlayers = 0;
var rl = readline.createInterface(process.stdin, process.stdout);
rl.question("How many Players should we test?", function(answer){
	numPlayers = answer;
	console.log(numPlayers);
	rl.pause();
});


//Ask for the Type of ELO
do{
	var typeELO = "";
	rl.question("Should the ELO be random or standard(1200)?\nType [r]andom or [s]tandard.", function(answer){
		typeELO = answer;
		console.log(typeELO);
		rl.pause();
	});
} while(typeELO != "r" || typeELO != "s");
//If ELO is random, set high and low points
var highELO;
var lowELO;
if(typeELO === "r"){
	//rl.resume();
	rl.question("Type the highest ELO", function(answer){
		highELO = answer;
		rl.pause();
	});
	//rl.resume();
	rl.question("Type the Lowest ELO", function(answer){
		lowELO = answer;
		rl.pause();
	});
}
//Create a new Array to store the players
var pArray = new Array();

//Store all the players with random or regular ELO in the array
for(var i = 0; i < numPlayers; i++){
	//Set the standard ELO, change if random
	var tempELO = 1200;
	if(typeELO === "r"){
		tempELO = Math.floor((Math.Random() * highELO) + lowELO);
	}
	//Use i as the name for now to keep track of the players
	pArray[i] = new Player(i, tempELO);
}

//Print all the players in the array, No games have been played yet.
//Change this to just print out all the fields using for/in loop
console.log("Name      ELO       Wins      Losses      W/L");
for(var i = 0; i < numPlayers; i++){
	console.log(pArray[i].name + " " + pArray[i].ELO + " " + pArray[i].numWins + " " + pArray[i].numLosses + " " + pArray[i].ratioWL);
}


//Close the input
rl.close();






















