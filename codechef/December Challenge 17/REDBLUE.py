import numpy as np
import math
from sklearn import svm
from sklearn import linear_model
if __name__ == '__main__':
    t = input()
    while t:
        n, m = map(int, raw_input().split())
        pts = []
        ans = []
        for i in range(n):
            pts.append(map(int, raw_input().split()))
            ans.append(0)
        for i in range(m):
            pts.append(map(int, raw_input().split()))
            ans.append(1)

        X = np.array(pts)
        y = np.array(ans)
        c = svm.LinearSVC(random_state=0)
        c.fit(X,y)
        tans = n+m
        # print c.coef_
        # print c.coef_[0][::-1]
        a = c.coef_[0][0]
        b = c.coef_[0][1]
        tn = math.tan(math.radians(0.5))
        # tn = 1
        for something in range(360):
            # coeffs = [1, 0]
            values = []
            for xi in pts:
                values.append((a*xi[0])+(b*xi[1]))
            # temp = zip(values, ans)
            temp = zip(values, pts, ans)
            temp.sort()
            # values, ans = zip(*temp)
            values, pts, ans = zip(*temp)

            bleft = 0
            rleft = 0
            bright = n
            rright = m
            # print values
            # print ans
            prev = values[0]-1
            for i, j in zip(values, ans):
                if i == prev:
                    if j == 0:
                        bleft += 1
                        bright -= 1
                    else:
                        rleft += 1
                        rright -= 1
                else:
                    tans = min([bleft + rright, bright + rleft, tans])
                    prev = i
                    if j == 0:
                        bleft += 1
                        bright -= 1
                    else:
                        rleft += 1
                        rright -= 1
                # print bleft, rleft, bright, rright, bleft + rright, bright + rleft
            tans = min([bleft + rright, bright + rleft, tans])

            slope = -a/b
            a = -(tn + slope)
            b = (1 - tn*slope)
            # print tans, a, b, slope

        print tans

        t -= 1