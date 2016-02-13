#include <cmath>

class LineAndCircle {
public:
    int judgeStat(int x1, int y1, int x2, int y2, int xc, int yc, int r) {
        double dis = fabs(1.0 * (y2 - y1) * xc - 1.0 * (x2 - x1) * yc - 1.0 * x1 * y2 + 1.0 * x2 * y1) / hypot(x2 - x1, y2 - y1);
        if (fabs(dis - r) < 1e-10)
        {
        	return 1;
        }
        return dis < r ? 2 : 0;
    }
};
