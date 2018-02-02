package program;

import javafx.application.Platform;
import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

import static program.Main.canvas;

public class MainView {

    public static void drawLine(int x0, int y0, int x1, int y1){
        Platform.runLater(() -> {
            javafx.scene.shape.Line line = new javafx.scene.shape.Line(x0, y0, x1, y1);
            line.setStrokeWidth(1);
            line.setStroke(Color.GREEN);
            Main.root.getChildren().add(line);
        });
    }
    public static void drawRectangle(int x, int y, int width, int height){
        Rectangle rectangle = new Rectangle(x,y,width,height);
        rectangle.setFill(Color.TRANSPARENT);
        rectangle.setStroke(Color.BLACK);
        Main.root.getChildren().add(rectangle);

//        drawLine(x,y, x+width,y);
    }
    public static void clearLines(){
        Platform.runLater(() -> {
            Main.root.getChildren().clear();
        });
    }

    public static void drawPixel(int x, int y){
            PixelWriter writer = canvas.getGraphicsContext2D().getPixelWriter();
            Color color = new Color(0, 0, 0, 1);
            writer.setColor(x, y, color);
    }

    public static void removePixel(int x, int y){
        PixelWriter writer = canvas.getGraphicsContext2D().getPixelWriter();
        Color color = new Color(1, 1, 1, 1);
        writer.setColor(x, y, color);
    }
    public static void clearCanvas(){
        canvas.getGraphicsContext2D().clearRect(0, 0, PixelsArray.WIDTH, PixelsArray.HEIGHT);
    }
    static void bresenhamLine(Integer x0, Integer y0, Integer x1, Integer y1) {
        boolean steep = Math.abs(y1 - y0) > Math.abs(x1 - x0);
        if (steep)
        {
            int temp = x0;
            x0 = y0;
            y0 = temp;

            temp = x1;
            x1 = y1;
            y1 = temp;
        }
        if (x0 > x1)
        {
            int temp = x0;
            x0 = x1;
            x1 = temp;

            temp = y0;
            y0 = y1;
            y1 = temp;
        }
        int dx = x1 - x0;
        int dy = Math.abs(y1 - y0);
        int error = dx / 2;
        int ystep = (y0 < y1) ? 1 : -1;
        int y = y0;
        for (int x = x0; x <= x1; x++)
        {
            PixelsArray.drawPixel(steep ? y : x, steep ? x : y);
            error -= dy;
            if (error < 0)
            {
                y += ystep;
                error += dx;
            }
        }
    }


}
