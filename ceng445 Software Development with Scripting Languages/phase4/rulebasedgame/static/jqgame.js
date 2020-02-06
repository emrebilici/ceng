
state = {
	selected : false,
	enteredGame : "",
	playername : "",
	playerid : 0,
	gameStarted : false,
	pick : "",
	gameOver : false,
	cells : [],
	deneme : "",
	cell2 : [],
	players : [],
	negeldi : "",
	nextTurn : "",
	currentTurn : "",
	winner : "",
	loser : "",
	gamisoverforplayer : false,
	playersPos : [],
	playersCredit : [],
	playersRound : [],
	playersArt : [],
	playersTurnType : [],
	hasToWait : 0


};

result = undefined;
myvar = 0;

function getCookie(name) {
    var cookieValue = null;
    if (document.cookie && document.cookie != '') {
        var cookies = document.cookie.split(';');
        for (var i = 0; i < cookies.length; i++) {
            var cookie = cookies[i].trim();
            // Does this cookie string begin with the name we want?
            if (cookie.substring(0, name.length + 1) == (name + '=')) {
                cookieValue = decodeURIComponent(cookie.substring(name.length + 1));
                break;
            }
        }
    }
    return cookieValue;
}


$(document).ready(function() {
    
    $("#enterNameBlock").fadeOut();

	$("#readyBlock").fadeOut();
	$("#gameBlock").fadeOut();
	$("#readyMsg").fadeOut();

	loadGames();
	
	$("#choosegameform [name=choose]").click(function() {
		state.enteredGame = $("#choosegameform [name=selectGame]").val();
		result = sendGame();
		if (result =="success"){
			$("#gamename").append("<h3>"+state.enteredGame+"</h3><br>")
		}
		return false;
	});

	$("#enterNameBlock [name=joinGame]").click(function (){
		state.playername = $("#enterNameBlock [name=name]").val();
	 	state.playerid = $("#enterNameBlock [name=id]").val();
	 	result = sendJoin(state.playername,state.playerid);
	 	if (result =="success"){
			$("#gamename").append("<h5>"+ "Hi, " +state.playername+"</h5>");
		}
		return false;
	});

	$("#readyBlock [name=readyOk]").click( function(){
		$("#readyBlock").fadeOut();
		result = sendReady();
		$("#readyMsg").fadeIn();
		$("#readyMsg").append("<h3>You are ready, "+state.playername+". Game will start if all players became ready!</h3>");
		myvar = setInterval(function(){
			result = checkReady();
			if (result == "yes"){
				return;
			}
		},500);
	});


	$("#gameBlock [name=turn]").click(function() {
		$("#gamename").html("<h3>"+state.enteredGame+"</h3><br>")
		$("#playername").html("<h2> You are: "+state.playername+"</h2><br>")
		//$("#cells").html("<h2> Cells: "+state.cells+"</h2><br>")

		state.pick = $("#gameBlock [name=pick]").val();
		$("#readyMsg").fadeOut();

		myvar = setInterval(function(){
			result = refreshTurn();
			if (result == "success2"){
				var content = "<table>"
				
				content += '<tr><td>' + 'Current Turn: ' +state.currentTurn+ '</td></tr>';
				content += '<tr><td>' + 'Ne geldi: ' +state.negeldi+ '</td></tr>';
				content += '<tr><td>' + 'Players Position: ' +state.playersPos+ '</td></tr>';
				content += '<tr><td>' + 'Players Credit: ' +state.playersCredit+ '</td></tr>';
				content += '<tr><td>' + 'Players playersRound: ' +state.playersRound+ '</td></tr>';
				content += '<tr><td>' + 'Players playersArt: ' +state.playersArt+ '</td></tr>';
				content += '<tr><td>' + 'Players playersTurnType: ' +state.playersTurnType+ '</td></tr>';
				content += '<tr><td>' + 'Players hasToWait: ' +state.hasToWait+ '</td></tr>';
				
				content += "</table>"

				var cellContent = "<table>"
				for (var i = 0; i < state.cell2.length; i++){
					cellContent += '<tr><td>' + 'Cell ' +  i + ' : ' +  state.cell2[i]+ '</td></tr>';
				}
				cellContent += "</table>";
				//$("#cells").html("<h2> Cells: "+state.cell2+"</h2><br>")
				if (state.gameOver=="true") {
					var gameOverContent = "<h2> GameOver: "+state.gameOver+"</h2><br>"
					var content = "<table>"
						
					content += '<tr><td>' + 'Current Turn: ' +state.currentTurn+ '</td></tr>';
					content += '<tr><td>' + 'Players Position: ' +state.playersPos+ '</td></tr>';
					content += '<tr><td>' + 'Players Credit: ' +state.playersCredit+ '</td></tr>';
					content += '<tr><td>' + 'Players playersRound: ' +state.playersRound+ '</td></tr>';
					content += '<tr><td>' + 'Players playersArt: ' +state.playersArt+ '</td></tr>';
					content += '<tr><td>' + 'Players playersTurnType: ' +state.playersTurnType+ '</td></tr>';
					content += '<tr><td>' + 'Ne geldi: ' +state.negeldi+ '</td></tr>';
					content += '<tr><td>' + 'winner: ' +state.winner+ '</td></tr>';
					content += '<tr><td>' + 'Loser: ' +state.loser+ '</td></tr>';
					content += "</table>";
					content += "<h3>If you want to play again click:</h3> <br> <a href="+ '/rulebasedgame'+">Again</a> ";
					$("#details").fadeOut();
					$("#cells").fadeOut();
					$("#gameOver").html(gameOverContent + content);

				}


				$("#cells").html(cellContent);
				$("#details").html(content);
				return;
			}
		}, 500);


		if (state.gameOver=="true") {
			var gameOverContent = "<h2> GameOver: "+state.gameOver+"</h2><br>"
			var content = "<table>"
				
			content += '<tr><td>' + 'Current Turn: ' +state.currentTurn+ '</td></tr>';
			content += '<tr><td>' + 'Players Position: ' +state.playersPos+ '</td></tr>';
			content += '<tr><td>' + 'Players Credit: ' +state.playersCredit+ '</td></tr>';
			content += '<tr><td>' + 'Players playersRound: ' +state.playersRound+ '</td></tr>';
			content += '<tr><td>' + 'Players playersArt: ' +state.playersArt+ '</td></tr>';
			content += '<tr><td>' + 'Players playersTurnType: ' +state.playersTurnType+ '</td></tr>';
			content += '<tr><td>' + 'Ne geldi: ' +state.negeldi+ '</td></tr>';
			content += '<tr><td>' + 'winner: ' +state.winner+ '</td></tr>';
			content += '<tr><td>' + 'Loser: ' +state.loser+ '</td></tr>';
			content += "</table>";

			content += "<h3>If you want to play again click:</h3> <br> <a href="+'/rulebasedgame'+">Again</a> ";
			$("#cells").fadeOut();
			$("#details").fadeOut();
			$("#gameOver").html(gameOverContent + content);

		}

		//result = sendTurn();
		
		result = sendTurn();
		if (result =="success"){
			var content = "<table>"
			content += '<tr><td>' + 'Current Turn: ' +state.currentTurn+ '</td></tr>';
			content += '<tr><td>' + 'Ne geldi: ' +state.negeldi+ '</td></tr>';
			content += '<tr><td>' + 'Players Position: ' +state.playersPos+ '</td></tr>';
			content += '<tr><td>' + 'Players Credit: ' +state.playersCredit+ '</td></tr>';
			content += '<tr><td>' + 'Players Round: ' +state.playersRound+ '</td></tr>';
			content += '<tr><td>' + 'Players Artifacts: ' +state.playersArt+ '</td></tr>';
			content += '<tr><td>' + 'Players TurnType: ' +state.playersTurnType+ '</td></tr>';
			content += '<tr><td>' + 'Players hasToWait: ' +state.hasToWait+ '</td></tr>';
			content += "</table>"

			var cellContent = "<table>"
			for (var i = 0; i < state.cell2.length; i++){
				cellContent += '<tr><td>' + 'Cell ' +  i + ' : ' +  state.cell2[i]+ '</td></tr>';
			}
			cellContent += "</table>";
			//$("#cells").html("<h2> Cells: "+state.cell2+"</h2><br>")

			$("#cells").html(cellContent)
			$("#details").html(content)
			
		}
		

		return false;
	});

	if(state.gameStarted){
		$("#readyMsg").html("");
		$("#readyMsg").append("<h3>Nice</h3>");
				
	}

	 
	//if choosen enterNameBlock will fade in
});

function sendReady(){

	$.getJSON(state.enteredGame + "/" + state.playerid + "/start", function (data){
		return;
	});
	return "success";
}

function checkReady(){
	var result;
	$.getJSON(state.enteredGame + "/" + state.playerid + "/checkready", function (data){
		if (data.result == "yes"){
			result = "yes";
			clearInterval(myvar);
			state.gameStarted = true;
			$("#gameBlock").fadeIn();
			
		}
		else{
			result = "no";
		}
	});
	return result;
}

function refreshTurn(){
	var result;
	$.getJSON(state.enteredGame + "/" + state.playerid + "/turn", function (data){
		state.cells = data.cells;

		console.log(jQuery.parseJSON(state.cells));

		state.deneme = jQuery.parseJSON(state.cells);
		state.cell2 = []
		for(var i =0; i < state.deneme.length; i++ ){
			state.cell2.push(JSON.stringify(state.deneme[i]));

		}

		var playerss = jQuery.parseJSON(data.playersPos);

		state.playersPos = []
		for(var i =0; i < playerss.length; i++ ){
			state.playersPos.push(JSON.stringify(playerss[i]));

		}

		var temp = jQuery.parseJSON(data.playersRound);

		state.playersRound = []
		for(var i =0; i < temp.length; i++ ){
			state.playersRound.push(JSON.stringify(temp[i]));

		}


		var temp2 = jQuery.parseJSON(data.playersCredit);

		state.playersCredit = []
		for(var i =0; i < temp2.length; i++ ){
			state.playersCredit.push(JSON.stringify(temp2[i]));

		}

		var temp3 = jQuery.parseJSON(data.playersArt);

		state.playersArt = []
		for(var i =0; i < temp3.length; i++ ){
			state.playersArt.push(JSON.stringify(temp3[i]));

		}


		var temp4 = jQuery.parseJSON(data.playersTurnType);

		state.playersTurnType = []
		for(var i =0; i < temp4.length; i++ ){
			state.playersTurnType.push(JSON.stringify(temp4[i]));

		}


		state.negeldi = data.negeldi;
		state.nextTurn = data.nextTurn;
		state.currentTurn = data.currentTurn;
		state.winner = data.winner;
		state.loser = data.loser;
		state.gamisoverforplayer = data.gamisoverforplayer;
		state.gameOver = data.gameOver;
		state.hasToWait = data.hasToWait;
	});
	return "success2";
}

function sendTurn(){
	var context;
	$.ajaxSetup({beforeSend: function(xhr, settings) {
			xhr.setRequestHeader("X-CSRFToken", getCookie('csrftoken'));
			}});
	$.post(state.enteredGame + "/" + state.playerid + "/turn", {'pick':state.pick}, function(data){
		//state.cells = JSON.stringify(data.cells);
		state.cells = data.cells;

		console.log(jQuery.parseJSON(state.cells));

		state.deneme = jQuery.parseJSON(state.cells);
		state.cell2 = []
		for(var i =0; i < state.deneme.length; i++ ){
			state.cell2.push(JSON.stringify(state.deneme[i]));

		}

		var playerss = jQuery.parseJSON(data.playersPos);

		state.playersPos = []
		for(var i =0; i < playerss.length; i++ ){
			state.playersPos.push(JSON.stringify(playerss[i]));

		}

		var temp = jQuery.parseJSON(data.playersRound);

		state.playersRound = []
		for(var i =0; i < temp.length; i++ ){
			state.playersRound.push(JSON.stringify(temp[i]));

		}


		var temp2 = jQuery.parseJSON(data.playersCredit);

		state.playersCredit = []
		for(var i =0; i < temp2.length; i++ ){
			state.playersCredit.push(JSON.stringify(temp2[i]));

		}

		var temp3 = jQuery.parseJSON(data.playersArt);

		state.playersArt = []
		for(var i =0; i < temp3.length; i++ ){
			state.playersArt.push(JSON.stringify(temp3[i]));

		}


		var temp4 = jQuery.parseJSON(data.playersTurnType);

		state.playersTurnType = []
		for(var i =0; i < temp4.length; i++ ){
			state.playersTurnType.push(JSON.stringify(temp4[i]));

		}

		state.negeldi = data.negeldi;
		state.nextTurn = data.nextTurn;
		state.currentTurn = data.currentTurn;
		state.winner = data.winner;
		state.loser = data.loser;
		state.gamisoverforplayer = data.gamisoverforplayer;
		state.gameOver = data.gameOver;
		state.hasToWait = data.hasToWait;
		//console.log(JSON.stringify(data.negeldi));
		//state.cell2
		//context =
		//data.name;
		//data.cells;
	});	
	return "success";
}

function sendJoin(name, id){
	$.ajaxSetup({beforeSend: function(xhr, settings) {
			xhr.setRequestHeader("X-CSRFToken", getCookie('csrftoken'));
			}});
	$.post(state.enteredGame + "/" + "ready",{'playername':name, 'playerid':id}, function (data){
		$("#enterNameBlock").fadeOut();
		$("#readyBlock").fadeIn();
		return;
	});
	return "success";		
}

function sendGame(){
	$.ajaxSetup({beforeSend: function(xhr, settings) {
			xhr.setRequestHeader("X-CSRFToken", getCookie('csrftoken'));
			}});
	$.post(state.enteredGame,{'game':state.enteredGame}, function (data){
		$("#chooseBlock").fadeOut();
		$("#enterNameBlock").fadeIn();
		return;
	});
	return "success";
}

function loadGames() {
	// body...
	$.get('/rulebasedgame/loadgames',function(data) {
		// body...
		for (var i = data.obj.length - 1; i >= 0; i--) {
			$("#choosegameform [name=selectGame]").append("<option value='" +data.obj[i] +"'>"+data.obj[i] +"</option>");
		}
		
	});
}