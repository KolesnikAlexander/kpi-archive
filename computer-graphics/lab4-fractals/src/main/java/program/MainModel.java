package program;

import javafx.scene.input.KeyCode;

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
//        Platform.runLater(() -> {
//            MainView.drawLine(10,
//                    PixelsArray.HEIGHT / 2,
//                    PixelsArray.WIDTH -10,
//                    PixelsArray.HEIGHT / 2 );
//        });
    }

    public static void keyPressed(KeyCode key){
        if (key == KeyCode.DIGIT1){
            algorithm1();
        }
        else if(key == KeyCode.N) {
            Alg1.iteration();
        }
        else if (key == KeyCode.DIGIT2) {
            algorithm2();
        }
        else if(key == KeyCode.DIGIT3) {
            algorithm3();
        }
        else if(key == KeyCode.C) {
            clear();
        }
    }

    public static void algorithm1(){
        System.out.println("Dot coordinates: "+PixelsArray.startX+ ":"+PixelsArray.startY);
        Alg1.run();

    }
    public static void algorithm2(){
        System.out.println("ALG2");
        Alg2.run();
    }
    public static void algorithm3(){
        System.out.println("ALG3");
        Alg3.run();
    }

    private static void clear() {
        MainView.clearLines();
    }
}
