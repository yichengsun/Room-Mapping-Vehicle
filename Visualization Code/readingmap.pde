import processing.serial.*;

Serial myPort;
float[][] obstacleMap;
float[][] actualMap;
float maxDistance;
int spacer;
int maxWidth = 44;
int maxHeight = 64;


void setup() {
    spacer = 15;
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
  size(maxWidth*spacer, maxHeight*spacer);
  noLoop();  // Run once and stop
}

void draw() {
  background(0);
  // This embedded loop skips over values in the arrays based on
  // the spacer variable, so there are more values in the array
  // than are drawn here. Change the value of the spacer variable
  // to change the density of the points
  for (int y = 0; y < height; y += spacer) {
    for (int x = 0; x < width; x += spacer) {
      stroke(0);
      int mycolor = int(obstacleMap[y/spacer][x/spacer]);
      if (mycolor == 0){
         fill(255, 255, 255);
      }
      else if (mycolor == 1){
        fill(255, 0, 0);
      }
      else if (mycolor == 2){
         fill(0, 0,0); 
      }
      else {
         fill(0, 0, 255);
      }
      rect(x, y, spacer, spacer);
    }
  }
}
