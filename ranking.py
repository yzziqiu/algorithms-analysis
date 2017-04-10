def Merge(A,B):
    A[p], B[q], R[p+q]
    i=1, j=1
    while ((M[A[i],B[j]]== 1) or j > q):
        if (M[A[i],B[j]]== 1):
            R[i+j-1] = A[i]
            i = i + 1
        else:
            R[i+j-1] = B[j]
            j = j + 1
    return R
def Rank(M,C):
    M[n,n], C[n]
    R[n]
    # base case 
    if n == 1: R[1] = C[1]
    if n == 2: 
        if M[C[1],C[2]] == 1:
            R[1] = C[1]
			R[2] = C[2]
        else:
			R[1] = C[2]
			R[2] = C[1]
    else 
        A = Rank(M[n,n], C.slice(1,n/2))
        B = Rank(M[n,n], C.slice(n/2+1,n))
        R =  Merge(A,B)
	print(R)
	
M[8][8] = [
       [0,0,0,1,0,0,1,1],
       [1,0,1,1,1,1,1,1],
       [1,0,0,1,1,0,0,1],
       [0,0,0,0,1,0,0,0],
       [1,0,0,0,0,1,1,0],      
	   [1,0,1,1,0,0,1,0],
	   [0,0,1,1,0,0,0,0],
	   [0,0,0,1,1,1,1,0]]
Rank(M,C)
