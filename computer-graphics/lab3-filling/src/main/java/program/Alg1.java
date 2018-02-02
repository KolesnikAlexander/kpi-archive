package program;

import javafx.application.Platform;
import javafx.concurrent.Task;

import java.util.Stack;
import java.util.concurrent.Semaphore;

import static program.PixelsArray.pixelIsFilled;

/**
 * Created by alex60070
 */
public class Alg1 extends Task<Void> {
    Stack<Pixel> stack = new Stack<>();
    @Override
    public Void call() throws Exception {

        int count = 0;

        stack.push(new Pixel(PixelsArray.startX, PixelsArray.startY));
        while (!stack.empty()){
            Pixel pixel = stack.pop();


            PixelsArray.drawPixel(pixel.x, pixel.y);

            Pixel newPixel = new Pixel(pixel.x+1, pixel.y);
            if (!pixelIsFilled(newPixel))
                stack.push(newPixel);

            newPixel = new Pixel(pixel.x, pixel.y+1);
            if (!pixelIsFilled(newPixel))
                stack.push(newPixel);

            newPixel = new Pixel(pixel.x-1, pixel.y);
            if (!pixelIsFilled(newPixel))
                stack.push(newPixel);

            newPixel = new Pixel(pixel.x, pixel.y-1);
            if (!pixelIsFilled(newPixel))
                stack.push(newPixel);

//            count++;
//            if (count >= 100){
//                Thread.sleep(20);
//                count = 0;
//            }

            System.out.println("PUSH: "+pixel.x+" : "+pixel.y+ "FIILED: "+pixelIsFilled(pixel));

        }
        System.out.println("END");
        return null;
    }

}
