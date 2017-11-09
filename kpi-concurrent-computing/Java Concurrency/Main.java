import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;

public class Main {
    public static Semaphore semP1;
    public static Semaphore semP4;

    public static CommonResource1 cr1;
    public static CommonResource2 cr2;

    public static CyclicBarrier cyclicBarrier;

    public static Producer producer1;
    public static Producer producer2;
    public static Producer producer3;
    public static Consumer consumer4;
    public static Producer producer5;

    public static boolean end = false;

    public static void main(String[] args) {
        try {
            System.setErr(new PrintStream(new File("log.txt")));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        System.out.println ("To stop running press Ctrl+C");

        cr1 = new CommonResource1();
        cr2 = new CommonResource2();
        cr2.changeValues();

        semP1 = new Semaphore(1, true);
        semP4 = new Semaphore(1, true);
        try {
            semP1.acquire();
            semP4.acquire();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        cyclicBarrier = new CyclicBarrier(3);


        producer1 = new Producer ( cr1,cr2, "Producer1" );
        producer2 = new Producer ( cr1,cr2, "Producer2" );
        producer3 = new Producer ( cr1,cr2, "Producer3" );
        consumer4 = new Consumer ( cr1, "Consumer4" );
        producer5 = new Producer ( cr1 ,cr2, "Producer5");

        try
        {
            producer1.thread.join();
            producer2.thread.join();
            producer3.thread.join();
            consumer4.thread.join();
            producer5.thread.join();
        } catch(InterruptedException e)
        {
            System.out.println("Main Interrupted");
        }
        System.err.println("Main ends");

    }
}
