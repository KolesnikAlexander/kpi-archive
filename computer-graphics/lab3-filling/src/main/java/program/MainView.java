package program;

import javafx.scene.image.PixelWriter;
import javafx.scene.paint.Color;
import static program.Main.canvas;

public class MainView {

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
