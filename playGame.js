//Testing Games for Smash ELO

//Order of operations:
///1. Ask for number of players
///2. Random or Standard ELO (1200)
///3. Tourny Style or Round Robin
///4. Print out all statistics to screen

function Player(name, ELO){
	this.name = name;
	this.ELO = ELO;
	this.numWins = 0;
	this.numLosses = 0;
};

// NULL -> INT
//Calculates the win/loss ratio
Player.prototype.ratioWL = function(){
	//Check for zero
	if(this.numWins + this.numLosses != 0){
		return this.numWins / (this.numLosses + this.numWins);
	}
	else {
		return 0;
	}
}

//Find the number of players from input
var getNumPlayers = function(){
	//TODO: ERROR CHECK
	return prompt("How many players are in the game?");
}

//Get the type of ELO
var getTypeELO = function(){
	//TODO: ERROR CHECK
	return prompt("Should the ELO be random or standard(1200)?\nType [r]andom or [s]tandard.");
}

