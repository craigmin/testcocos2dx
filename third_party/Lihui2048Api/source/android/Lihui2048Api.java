/*
java implementation of the Lihui2048Api extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;

class Lihui2048Api
{
    public boolean isMovable()
    {
        return false;
    }
    public void move(int type)
    {
        
    }
    public int getCurrentScore()
    {
        return 0;
    }
    public int getBestScore()
    {
        return 0;
    }
    public void reset()
    {
        
    }
    public boolean isWin()
    {
        return false;
    }
    public int getValue(int x, int y)
    {
        return 0;
    }
    public int getAnim(int x, int y)
    {
        return 0;
    }
    public void cleanRect(int x, int y)
    {
        
    }
    public void reArrange()
    {
        
    }
}
