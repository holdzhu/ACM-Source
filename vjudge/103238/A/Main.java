import java.io.*;
import java.util.*;
import java.math.*;

class Main {
	static BigDecimal p[] = new BigDecimal[55];
	static BigDecimal q[] = new BigDecimal[55];
	static BigDecimal tmp[] = new BigDecimal[55];

	static BigDecimal solve(int k, int l, int r) {
		if (k < l)
			return BigDecimal.ONE;
		if (k > r)
			return BigDecimal.ZERO;
		tmp[l - 1] = BigDecimal.ZERO;
		for (int i = l + 1; i <= k; ++i) {
			tmp[i - 1] = q[i].divide(BigDecimal.ONE.subtract(tmp[i - 2].multiply(p[i - 2])), 1000, BigDecimal.ROUND_DOWN);
		}
		tmp[r + 1] = BigDecimal.ZERO;
		for (int i = r - 1; i >= k; --i) {
			tmp[i + 1] = p[i].divide(BigDecimal.ONE.subtract(tmp[i + 2].multiply(q[i + 2])), 1000, BigDecimal.ROUND_DOWN);
		}
		BigDecimal res = BigDecimal.ONE.divide(BigDecimal.ONE.subtract(tmp[k - 1].multiply(p[k - 1])).subtract(tmp[k + 1].multiply(q[k + 1])), 1000, BigDecimal.ROUND_DOWN);
		for (int i = k - 1; i >= l; --i)
			res = res.multiply(tmp[i]);
		return res.multiply(q[l]);
	}

	public static void main(String[] args) {
		for (int i = 0; i <= 54; ++i) {
			tmp[i] = BigDecimal.ZERO;
			p[i] = BigDecimal.ZERO;
			q[i] = BigDecimal.ZERO;
		}
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int k = input.nextInt();
		for (int i = 1; i < n; ++i) {
			p[i] = input.nextBigDecimal();
			q[i] = BigDecimal.ONE.subtract(p[i]);
		}
		BigDecimal ans = n == 2 ? BigDecimal.ONE : solve(k, 2, n - 1).multiply(BigDecimal.ONE.subtract(solve(1, 1, n - 1))).add(solve(n - 1, 1, n - 1).multiply(BigDecimal.ONE.subtract(solve(k, 1, n - 2))));
		System.out.printf("%.10f\n", ans);
		input.close();
	}
}