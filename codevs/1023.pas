var
    n,i,j:longint;
    a,b:array[1..10] of real;
    sum,asum:real;
begin
    readln(n);
    for i:=1 to n do
    begin
        readln(a[i],b[i]);
        sum:=sum+a[i]*b[i];
        asum:=asum+a[i];
    end;
    writeln(sum/asum:0:2);
end.