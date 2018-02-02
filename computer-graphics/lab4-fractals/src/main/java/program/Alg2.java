package program;

/**
 * Created by alex60070
 */
public class Alg2 {
    //Mandelbrot set
    static int max = 0;
    public static void run(){
        MainView.clearCanvas();
        int height = PixelsArray.HEIGHT;
        int width = PixelsArray.WIDTH;
        max++;
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                double c_re = (col - width/2.0)*4.0/width;
                double c_im = (row - height/2.0)*4.0/width;
                double x = 0, y = 0;
                int iteration = 0;
                while (x*x+y*y <= 4 && iteration < max) {
                    double x_new = x*x - y*y + c_re;
                    y = 2*x*y + c_im;
                    x = x_new;
                    iteration++;
                }
                if (iteration >= max)
                    MainView.drawPixel(col, row);
            }
        }
    }
}
