/**
 * Created by alex6 on 19.05.2017.
 */
class CommonResource1
{
    public static final int MaxBufSize = 10;
    public static final int MinBufSize = 0;
    private int CR1[] = new int[MaxBufSize+1];
    int ind = 0;
    boolean IsEmpty = ind  == MinBufSize;
    boolean IsFull = ind == MaxBufSize;
    private int emtCouner = 0;
    private int overCouner = 0;

    synchronized void consume()
    {
        endConsCondition();//<--------------------
        if (!IsEmpty)
        {
            System.err.println(Thread.currentThread().getName() + " takes an element");
            System.err.println("--- cr1[" + ind + "] = " + CR1[ind]);
            CR1[ind] = 0;
            System.err.println("--- ind: " + ind-- + " => " + ind);
            System.err.println();

            IsEmpty = ind == MinBufSize;
            IsFull = false;
        }
    }
    void endConsCondition(){
        if (IsEmpty)
        {
            emtCouner++;
        }
        if ((emtCouner > 2) && (overCouner > 2))
        {
            Main.end = true;
        }
    }
    void endProdCondition(){
        if (IsFull)
        {
            overCouner++;
        }
        if ((emtCouner > 2) && (overCouner > 2))
        {
            Main.end = true;
        }
    }


    synchronized void produce ()
    {
        endProdCondition();//<---------------

        if (!IsFull)
        {
            System.err.println(Thread.currentThread().getName() + " pushes an element");
            System.err.println("+++ ind: " + ind++ +" => " + ind);
            CR1[ind] = ind;
            System.err.println("+++ cr1[" + ind + "] = " + CR1[ind]);
            System.err.println();

            IsFull = ind == MaxBufSize;
            IsEmpty = false;
        }

    }
}