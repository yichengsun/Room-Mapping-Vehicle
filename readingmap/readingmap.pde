import processing.serial.*;

Serial myPort;
float[][] obstacleMap;
float[][] actualMap;
float maxDistance;
int spacer;
int maxWidth = 22;
int maxHeight = 32;


void setup() {
  obstacleMap = new float[maxHeight][maxWidth];
  String lines[] = loadStrings("roommap.txt");
  for (int i = 0; i < lines.length; i++){
    String[] isObstacle =lines[i].split(" ");
    print(i);
    if (isObstacle.length < 1) continue;
    for (int j = 0; j < isObstacle.length; j++){
       obstacleMap[i][j] = int(isObstacle[j]);
    }
    println(); 
  }
  for (int i = 0; i < obstacleMap.length; i++){
     for (int j = 0; j < obstacleMap[0].length; j++){
        print (obstacleMap[i][j] + " ");
     } 
     println();
  }
  size(maxWidth*30, maxHeight*30);
  maxDistance = dist(width/2, height/2, width, height);
  actualMap = new float[width][height];
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      float distance = dist(width/2, height/2, x, y);
      actualMap[x][y] = distance/maxDistance * 255;
    }
  }
  spacer = 30;
  noLoop();  // Run once and stop
}

void draw() {
  background(0);
  // This embedded loop skips over values in the arrays based on
  // the spacer variable, so there are more values in the array
  // than are drawn here. Change the value of the spacer variable
  // to change the density of the points
  for (int y = 0; y < height; y += 30) {
    for (int x = 0; x < width; x += 30) {
      stroke(255);
      point(x + spacer/2, y + spacer/2);
    }
  }
}
