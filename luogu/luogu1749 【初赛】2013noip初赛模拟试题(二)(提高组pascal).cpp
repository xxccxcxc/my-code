C
C
D
B
A
C
A
C
C
B
ABC
ABD
BC
BC
AC
CD
ABC
ACD
ACD
ABCD
MLGB
C(N,3)+4*C(N,4)+5*C(N,5)+6*C(N,6)
405
69
15
403
s:=0
s:=s+a[i1,j1]
max:=s
p+p1-1
q+q1-1
inc(map[x,0])
f[x,1]:=a[x]
vst[map[x,i]]=0
solve(map[x,i])
f[x,0]+max(f[map[x,i],1],f[map[x,i],0])
f[x,1]+f[map[x,i],0]
