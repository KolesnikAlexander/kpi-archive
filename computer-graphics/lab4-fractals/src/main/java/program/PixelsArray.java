package program;

import javafx.application.Platform;

import java.util.LinkedList;
import java.util.List;

/**
 * Created by alex60070
 */
public class PixelsArray {
    public static final int WIDTH = 850;
    public static final int HEIGHT = 650;

    public static boolean[][] pixels = new boolean[WIDTH][HEIGHT];
    public static int startX;
    public static int startY;

    public static List<Line> borders = new LinkedList<>();

    public static void drawPixel(int x, int y){
        Platform.runLater(new Runnable() {
            @Override
            public void run() {
                MainView.drawPixel(x, y);
            }
        });

        pixels[x][y] = true;
    }

    public static void removePixel(int x, int y){
        Platform.runLater(new Runnable() {
            @Override
            public void run() {
                MainView.removePixel(x, y);
            }
        });

        pixels[x][y] = false;
    }

    public static boolean pixelIsFilled(Point point){
            return pixels[point.getX()][point.getY()];
    }
    public static void clearArray(){
        pixels = new boolean[WIDTH][HEIGHT];
    }
}
