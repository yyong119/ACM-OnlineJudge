var
        yanghui:array[1..1001,1..1001] of int64;
        n,m,k,a,b,i,j,l:longint;
begin
        readln(a,b,k,n,m); yanghui[1,1]:=1;
        for i:=2 to k+1 do
                for j:=1 to i do
                begin
                        if j=1 then yanghui[i,j]:=yanghui[i-1,j]*a mod 10007
                        else
                        if j=i then yanghui[i,j]:=yanghui[i-1,j-1]*b mod 10007
                        else yanghui[i,j]:=(yanghui[i-1,j-1]*b+yanghui[i-1,j]*a) mod 10007;
                end;
        writeln(yanghui[k+1,k-n+1] mod 10007);
end.