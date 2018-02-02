package program;

import javafx.concurrent.Task;

import java.util.Stack;

import static program.PixelsArray.*;

/**
 * Created by alex60070
 */
    public class Alg3 extends Task<Void> {

        private Pixel getNextPixel(Pixel current) {
            if (current.getX() >= WIDTH - 1)
                return null;

            Pixel newPixel = new Pixel(current.getX() + 1, current.getY());

            if (!PixelsArray.pixelIsFilled(newPixel)){
                return newPixel;
            }
            else {
                int x = newPixel.getX();
                int y = newPixel.getY();

                do {
                    newPixel = new Pixel(x, y);
                    if (!PixelsArray.pixelIsFilled(newPixel))
                        break;
                } while (++x <= PixelsArray.WIDTH);

                if (!PixelsArray.pixelIsFilled(newPixel))
                    return new Pixel(newPixel.getX() - 1, newPixel.getY());
                else
                    return newPixel;
            }
        }

        @Override
        public Void call() throws Exception {
            Pixel first = null;
            Pixel last = null;
            boolean lineIsEmpty;

            Pixel current;
            boolean prevFilled;
            boolean curFilled;

            for (int y = 0; y < PixelsArray.HEIGHT; y++) {
                current = getNextPixel(new Pixel(0, y));
                prevFilled = false;
                lineIsEmpty = true;

                while (current != null) {
                    curFilled = pixelIsFilled(current);

                    if (curFilled)
                        lineIsEmpty = false;

                    if (curFilled && (first == null))
                        first = current;

                    if ((curFilled && !prevFilled) ||
                            (!curFilled && prevFilled)){
                        PixelsArray.drawPixel(current.getX(), current.getY());
                        prevFilled  = true;
                    }
                    else
                        prevFilled = false;
                    current = getNextPixel(new Pixel(current.getX(), current.getY()));
                }

                if (!(first == null) && lineIsEmpty) {

                    try{
                        deleteFirstAndLast(first.getY(), y - 1);
                    }catch (Exception e){
                        System.out.println(e);
                    }


                }
            }
            System.out.println("END");
            return null;
        }

    private void deleteFirstAndLast(int firstY, int lastY) {
        for (int x = 0; x < PixelsArray.WIDTH; x++) {
            removePixel(x, firstY);
            removePixel(x, lastY);
        }

        }
    }
