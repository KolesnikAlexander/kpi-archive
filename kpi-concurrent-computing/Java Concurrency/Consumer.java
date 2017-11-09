/**
 * Created by alex6 on 19.05.2017.
 */
public class Consumer implements Runnable
{
    CommonResource1 CR;
    Thread thread;

    Consumer (CommonResource1 CR_arg, String name)
    {
        this.CR = CR_arg;
        thread = new Thread (this, name);
        thread.start();
    }

    public void run()
    {
        while (true)
        {
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            CR.consume();
            /** Synchronisation with semaphores */
                try {
                    Main.semP1.release();
                    Main.semP4.acquire();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }


            if (Main.end ){ //<----------------------------
                {
                    Main.semP1.release();
                    System.err.println(" === END === " +Thread.currentThread().getName());
                    Producer.displayStates();
                        return;
                }
            }
        }
    }
}

