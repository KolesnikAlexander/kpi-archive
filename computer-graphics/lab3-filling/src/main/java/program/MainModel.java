package program;

import javafx.application.Platform;
import javafx.scene.input.KeyCode;
import javafx.scene.input.MouseEvent;

import java.util.LinkedList;

import static program.MainView.bresenhamLine;


/**
 * Created by alex60070
 */
public class MainModel {
    private static boolean lineStarted = false;
    private static int firstX;
    private static int firstY;
    private static int prevX;
    private static int prevY;

    private static boolean startPointMode = false;

    public static void start() {
        Platform.runLater(() -> {

        });
    }
    public static void canvasClickModel(MouseEvent mouseEvent) {
        if (startPointMode){
            PixelsArray.startX = (int)mouseEvent.getSceneX();
            PixelsArray.startY = (int)mouseEvent.getSceneY();
            algorithm1();
            startPointMode = false;
            return;
        }

        if (!lineStarted){
            lineStarted = true;

            prevX = (int)mouseEvent.getSceneX();
            prevY = (int) mouseEvent.getSceneY();

            firstX = prevX;
            firstY = prevY;
        }
        else {
            int endX = (int) mouseEvent.getSceneX();
            int endY = (int) mouseEvent.getSceneY();

            bresenhamLine(prevX, prevY, endX, endY);

            Line line = new Line();
            line.setStartX(prevX);
            line.setStartY(prevY);
            line.setEndX(endX);
            line.setEndY(endY);
            PixelsArray.borders.add(line);

            prevX = endX;
            prevY = endY;
        }
    }

    public static void addLineToBorders(int prevX,int prevY,int endX,int endY){
        Line line = new Line();
        line.setStartX(prevX);
        line.setStartY(prevY);
        line.setEndX(endX);
        line.setEndY(endY);
        PixelsArray.borders.add(line);
    }

    public static void keyPressed(KeyCode key){
        if (!lineStarted){
            System.out.println("Draw a polygon");
            return;
        }
        if (key == KeyCode.DIGIT1){
            bresenhamLine(firstX, firstY, prevX, prevY);
            inputStartDot();
        }
        else if (key == KeyCode.DIGIT2) {
            bresenhamLine(firstX, firstY, prevX, prevY);
            addLineToBorders(firstX, firstY, prevX, prevY);
            algorithm2();
        }
        else if(key == KeyCode.DIGIT3) {
            bresenhamLine(firstX, firstY, prevX, prevY);
            algorithm3();
        }
        else if(key == KeyCode.C) {
            clear();
        }

    }

    private static void clear() {
        lineStarted = false;
        startPointMode = false;
        MainView.clearCanvas();
        PixelsArray.clearArray();
        PixelsArray.borders = new LinkedList<>();

    }

    public static void inputStartDot(){
        System.out.println("Input start pixel");
        startPointMode = true;
    }
    public static void algorithm1(){
        System.out.println("Dot coordinates: "+PixelsArray.startX+ ":"+PixelsArray.startY);
        Thread th = new Thread(new Alg1());
        th.setDaemon(true);
        th.start();
    }
    public static void algorithm2(){
        System.out.println("ALG2");
        Thread th = new Thread(new Alg2());
        th.setDaemon(true);
        th.start();
    }
    public static void algorithm3(){
        System.out.println("ALG3");
        Thread th = new Thread(new Alg3());
        th.setDaemon(true);
        th.start();
    }
}
