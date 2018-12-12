var particles = [];

var NUM_NODES = 50;
var NUM_STRINGS = 35;

// var prevX;
// var prevY;
var velX;
var velY;

var pos = new Array (NUM_NODES * NUM_STRINGS);




const FOLDER = 'assets/', EXT = '.mp3',
	  INDEX_START = 1, INDEX_END = 35,
	  INDEX_TOTAL = 1 + INDEX_END - INDEX_START,
	  sound = new Array(INDEX_TOTAL);

let video;
let PoseNet;
let poses = [];
let skeletons = [];

var videoX;
var videoY;

var color = 0;


var drawX;
var drawY;
var prev_smoothX = 0;
var prev_smoothY = 0;

let smooth_keypoints = [];
let prev_keypoints = [];
// let prev_smooth = [];

function preload(){

	for(let i = 0; i < INDEX_TOTAL; ++i){

		sound[i] = loadSound(FOLDER + (i + INDEX_START)+ EXT);

	}


}

	
function setup(){

	
	createCanvas(windowWidth, windowHeight);
	background(0);
	frameRate(60);


	// fill(255, 30);
	// stroke(255, 0);

	for(var i = 0; i < 300; i++){

		this.p = new Particle(createVector(width/2, height/2), createVector(0, 0), random(50, 70));
		particles.push(p);

	}


	video = createCapture(VIDEO);
	video.size(windowWidth, windowHeight);
	poseNet = ml5.poseNet(video, modelReady);
	poseNet.on('pose', function(results){
		poses = results;
		console.log(poses);
	});

	video.hide();



	// prevPos = mouseX;

	// prevX = videoX;

	for(var i = 0; i < NUM_NODES * NUM_STRINGS; i++){

		pos[i] = 0;

	}


}


function modelReady(){

	select('#status').html('Model Loaded');

}



function draw(){

	// smooth pose points 
	if(smooth_keypoints.length == 0 && poses.length > 0){
		let pose = poses[0].pose;
		for(let j = 0; j < pose.keypoints.length; j++){

			let keypoint = pose.keypoints[j];
			smooth_keypoints.push({position:{"x":0,"y":0}});
			prev_keypoints.push({position:{"x":0,"y":0}});
			// prev_smooth.push({position:{"x":0,"y":0}});
		}
	}else if(poses.length > 0){

		// smooth them with new values
		let pose = poses[0].pose;
		for(let j = 0; j < pose.keypoints.length; j++){

			let keypoint = pose.keypoints[j];
			let x = smooth_keypoints[j].position.x;
			let y = smooth_keypoints[j].position.y;
			prev_keypoints[j].position.x = x;
			prev_keypoints[j].position.y = y;

			smooth_keypoints[j].position.x = .5*smooth_keypoints[j].position.x + .5*keypoint.position.x;
			smooth_keypoints[j].position.y = .5*smooth_keypoints[j].position.y + .5*keypoint.position.y;

		}

	}

	let limit = Math.min(poses.length,1);
	for(let i = 0; i < limit; i++){
	//for(let i = 0; i < poses.length; i++){

		let pose = poses[i].pose;

		for(let j = 0; j < pose.keypoints.length; j++){

			//let keypoint = pose.keypoints[j];
			let keypoint = smooth_keypoints[j];

			//if(keypoint.score > 0.2){

				videoX = keypoint.position.x;
				videoY = keypoint.position.y;

				let prevX = prev_keypoints[j].position.x;
				let prevY = prev_keypoints[j].position.y;

				// let prev_smoothX = prev_smooth[j].position.x;

				velX = videoX - prev_smoothX;
				velY = videoY - prev_smoothY;

				drawX = round(float(videoY) * NUM_NODES / height);

				drawY = NUM_NODES * round(float(videoX) * NUM_STRINGS / width) + drawX;

				if( drawX > 5 && drawX < NUM_NODES - 5 && drawY > 5 && drawY < NUM_NODES * NUM_STRINGS - 5){

					pos[drawY] += velX;
					pos[drawX] += velY;
					// pos[drawY - NUM_STRINGS] += velX * 0.3;
					// pos[drawX] += velY * 0.5;

				}


				for(var a = 0; a < NUM_NODES * NUM_STRINGS; a++){

					pos[a] *= 0.7;

				}


				background(0);
				// fill(0);	
				strokeWeight(0.5);
				// stroke(255);

				fill(255, 50);
				stroke(255, 0);


	

				for(var b = 0; b < NUM_STRINGS; b++){


					if( videoX < (width * b)/NUM_STRINGS + 5 && videoX > (width * b)/NUM_STRINGS - 5){

						

						var volume = map(videoY, 0, height, 0, 1);
						volume = constrain(volume, 0, 1);

						var speed = map(videoY, 0.1, height, 0, 2);
						speed = constrain(speed, 0.01, 2);

						sound[b].amp(1 - volume);
						// sound[b].rate(2 - speed);



						let dist_val = dist(videoX, videoY, prevX, prevY);

						console.log('dist ' + dist_val);

						if(dist(videoX, videoY, prevX, prevY) > 20){

							sound[b].play();

							console.log('play： ' + dist_val);

							color = 1;

						}else{

						color = 0;

					}



					}

				beginShape();

						for(var c = 0; c < NUM_NODES; c++){

							curveVertex((width * b)/ NUM_STRINGS + pos[b * NUM_NODES + c] + randomGaussian(), float(c * height / NUM_NODES) + randomGaussian());

						}

				endShape();

					// background(0);

				}


				prev_smoothX = videoX;
				prev_smoothY = videoY;

				
				// fill(255, 0, 0);
    //     		noStroke();
    //     		ellipse(keypoint.position.x, keypoint.position.y, 10, 10);

			}

		//}

	}

	// image(video, 0, 0, 320, 240);


	// drawKeypoints();
	// drawSkeleton();

	// draw smoothed
	for(let i = 0; i < smooth_keypoints.length; i++){

		fill(255, 10);
		stroke(255, 0);
        let keypoint = smooth_keypoints[i];
        ellipse(keypoint.position.x, keypoint.position.y, 15, 15);

 

        console.log(color);

        
		for(var p = 0; p < particles.length; p++){

			if (color == 1){

        	fill(random(255),random(255),random(255));


        	}else{


        	fill(255, 10);
        	

        }

			particles[p].draw(width - keypoint.position.x, width - prev_smoothX, keypoint.position.y, prev_smoothY);
			particles[p].move();
		}
     }
	


}


// function drawKeypoints(){

// 	for (let i = 0; i < poses.length; i++) {
//     // For each pose detected, loop through all the keypoints
//     for (let j = 0; j < poses[i].pose.keypoints.length; j++) {
//       // A keypoint is an object describing a body part (like rightArm or leftShoulder)
//       let keypoint = poses[i].pose.keypoints[j];
//       // Only draw an ellipse is the pose probability is bigger than 0.2
//       if (keypoint.score > 0.2) {
//         fill(255, 0, 0);
//         noStroke();
//         ellipse(keypoint.position.x, keypoint.position.y, 10, 10);
//       }
//     }
//   }


// }


// function drawSkeleton() {
//   // Loop through all the skeletons detected
//   for (let i = 0; i < poses.length; i++) {
//     // For every skeleton, loop through all body connections
//     for (let j = 0; j < poses[i].skeleton.length; j++) {
//       let partA = poses[i].skeleton[j][0];
//       let partB = poses[i].skeleton[j][1];
//       stroke(255, 0, 0);
//       line(partA.position.x, partA.position.y, partB.position.x, partB.position.y);
//     }
//   }
// }






function Particle(l, v, s){

	this.loc = l;
	this.vel = v;
	this.s = s;
	this.ms = s;



	this.draw = function(posX, prevPosX, posY, prevPosY){

		strokeWeight(1 + this.s / 10);
		rectMode(RADIUS);
		rect(this.loc.x, this.loc.y, this.s, 0.2);


		if(this.s > 0){

			this.s -= 0.3;

		}

		else{

			this.s = this.ms;

			var newVel = createVector(0, 0);
			newVel.normalize();
			newVel.mult(2);

			newVel.y = random(-0.1, 0.1);
			// newVel.y += random(0, 0.2);

			this.update(createVector(posX, posY), newVel);

		}

	}

	this.update = function(l, v){

		this.loc = l;
		this.vel = v;

	}

	this.move = function(){

		this.loc.add(this.vel);

	}


}
