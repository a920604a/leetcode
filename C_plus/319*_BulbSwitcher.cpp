class Solution {
public:
    int bulbSwitch(int n) {
        // 計算有最後有多少盞燈是亮著的
        // 第幾輪操作，就是把每x盞燈的開關按一下。
        // 假設只有6盞燈，總共會有6輪操作，對於第六盞燈會被按下幾次開關？第１、２、３、６輪都會被按下，因為 6 = 1*6 = 2*3，因數都是成對的，所以會被按下四次
        // 假設總共16盞燈，那第１６盞燈會被按幾次？ 16 = 1*16 = 2*8 = 4*4，會被按下5次
        // 假設總共16盞燈，16平方根等於4，代表著最後有4盞燈是亮著，分別是 第 1*1 2*2 3*3 4*4 盞燈
        return sqrt(n);
    }
};