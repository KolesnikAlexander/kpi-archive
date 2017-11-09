import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Created by alex6 on 19.05.2017.
 */
public class Producer implements Runnable
{
    CommonResource1 cr1;
    CommonResource2 cr2;

    Thread thread;
    private static int cBThreadsTerminated;

    Producer (CommonResource1 cr1, CommonResource2 cr2, String name)
    {
        this.cr1 = cr1;
        this.cr2 = cr2;
        thread = new Thread (this, name);
        thread.start();
    }

    public void run()
    {
        while (true)
        {
            try {
                Thread.sleep(20);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            /** Common resource 2 access */
            if (Thread.currentThread().getName().equals("Producer1")||
                    Thread.currentThread().getName().equals("Producer2")||
                    Thread.currentThread().getName().equals("Producer3"))
            {
                cr2.mutex.lock();
                    System.err.println(Thread.currentThread().getName() + " changes cr2");
                    cr2.changeValues();
                    System.err.println(cr2);
                cr2.mutex.unlock();
            }

            /** Producing task execution */
            cr1.produce();

            /** Cyclic barrier */
            if (Thread.currentThread().getName().equals("Producer2")||
                    Thread.currentThread().getName().equals("Producer3")||
                    Thread.currentThread().getName().equals("Producer5"))
            {

                try {
                    Main.cyclicBarrier.await();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } catch (BrokenBarrierException e) {
                    e.printStackTrace();
                }

            }
            /** Synchronisation with semaphores */
            if(Thread.currentThread().getName().equals("Producer1")){
                try {
                    Main.semP4.release();
                    Main.semP1.acquire();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

            }

            if (Main.end){
                if (Thread.currentThread().getName().equals("Producer2")||
                        Thread.currentThread().getName().equals("Producer3")||
                        Thread.currentThread().getName().equals("Producer5"))
                {
                    cBThreadsTerminated++;
                    while(cBThreadsTerminated < Main.cyclicBarrier.getParties()){
                        if (Main.cyclicBarrier.getNumberWaiting() > 0)
                            break;
                    }
                    if (Main.cyclicBarrier.getNumberWaiting() > 0)
                        continue;

                }
                if(Thread.currentThread().getName().equals("Producer1")){
                    Main.semP4.release();
                }

                System.err.println(" === END === " +Thread.currentThread().getName());
                displayStates();

                return;
            }
        }
    }
    public static void displayStates(){
        System.err.println("         ====== " +Main.producer1.thread.getName() + ": " +
                Main.producer1.thread.getState());
        System.err.println("         ====== " +Main.producer2.thread.getName() + ": " +
                Main.producer2.thread.getState());
        System.err.println("         ====== " +Main.producer3.thread.getName() + ": " +
                Main.producer3.thread.getState());
        System.err.println("         ====== " +Main.consumer4.thread.getName() + ": " +
                Main.consumer4.thread.getState());
        System.err.println("         ====== " +Main.producer5.thread.getName() + ": " +
                Main.producer5.thread.getState());
    }
}
