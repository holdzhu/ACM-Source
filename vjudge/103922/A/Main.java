import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static int[][] parents = new int[300][2];
	static BigDecimal[] p1 = new BigDecimal[300];
	static BigDecimal[] p2 = new BigDecimal[300];
	static int n;
	static int[] deg = new int[300];

	static void solve(int u, int v, BigDecimal[] p)
	{
		for (int i = 0; i < n; ++i) {
			p[i] = BigDecimal.ZERO;
			deg[i] = 0;
		}
		p[u] = BigDecimal.ONE;
		Queue<Integer> q = new LinkedList<Integer>();
		for (int i = 0; i < n; ++i) {
			if (parents[i][0] != -1) {
				deg[parents[i][0]]++;
				deg[parents[i][1]]++;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (deg[i] == 0) {
				q.add(i);
			}
		}
		while (true) {
			Integer t = q.poll();
			if (t != null) {
				if (parents[t][0] != -1) {
					if (t != v) {
						p[parents[t][0]] = p[parents[t][0]].add(p[t].divide(BigDecimal.valueOf(2)));
						p[parents[t][1]] = p[parents[t][1]].add(p[t].divide(BigDecimal.valueOf(2)));
					}
					if (--deg[parents[t][0]] == 0) {
						q.add(parents[t][0]);
					}
					if (--deg[parents[t][1]] == 0) {
						q.add(parents[t][1]);
					}
				}
			}
			else
				break;
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		n = input.nextInt();
		int k = input.nextInt();
		for (int i = 0; i < n; ++i)
			parents[i][0] = parents[i][1] = -1;
		for (int i = 0; i < k; ++i) {
			int u = input.nextInt();
			int v = input.nextInt();
			int w = input.nextInt();
			u--; v--; w--;
			parents[u][0] = v;
			parents[u][1] = w;
		}
		int m = input.nextInt();
		while (m --> 0) {
			int u = input.nextInt() - 1;
			int v = input.nextInt() - 1;
			solve(u, v, p1);
			solve(v, u, p2);
			BigDecimal ans = BigDecimal.ZxzaERO;
			for (int i = 0; i < n; ++i)
				ans = ans.add(p1[i].multiply(p2[i]));
			System.out.println(ans.multiply(BigDecimal.valueOf(100)).stripTrailingZeros().toPlainString() + "%");
		}
		input.close();
	}
}