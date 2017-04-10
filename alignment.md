~~~~
L[i,j] = 
    \begin{cases}
        L[i-1,j-1],& \text{if}\ P[i] = Q[j] \ and \ i = j \\
        min(L[i-1,j-1]+d, min(L[i-1,j]+g, L[i,j-1]+g)), & \text{if} \ P[i] \neq Q[j] \ and \ i, j > 0
    \end{cases}

\vspace{3mm}
\textbf{Question 2}

dynamic programming
\begin{lstlisting}
//assume P[1...n] and Q[1...m]
//L[n,m] to store the penalty score
//gap:g, mismatch:d
for i=0 to length(P)
	L[i,0] = gi
for j=0 to length(Q)
	L[0,j] = gj
for i=1 to length(P)
	for j=1 to length(Q)
	   if i = j and P[i] = Q[j]
	        L[i,j] = L[i-1,j-1]
	   else
	    L[i,j] = min(L[i-1,j-1]+d, min(L[i-1,j]+g, L[i,j-1]+g))
			


AlignmentP <- ""
AlignmentQ <- ""
i = length(P)
j = length(Q)
while(i>0 or j>0)
{   //add to alignment directly if matched or mismatched
	if(i>0 and j>0 and (L[i,j] == L[i-1,j-1] or L[i,j] ==L[i-1,j-1]+d))
	{
	AlignmentP <- P[i]+AlignmentP
	AlignmentQ <- Q[j]+AlignmentQ
	i=i-1, j=j-1
	}
	else if (i > 0 and L[i,j] == L[i-1,j]+g)
	{
	AlignmentP <- P[i]+AlignmentP
	AlignmentQ <- "_"+AlignmentQ
	i=i-1
	}
	else
	{
	AlignmentP <- "_"+AlignmentP
	AlignmentQ <- Q[j]+AlignmentQ
	j=j-1
	}
}
for a = 1 to length(AlignmentP)
	print ("(" + AlignmentP[a] + "," + AlignmentQ[a] + ")")
  ~~~~
