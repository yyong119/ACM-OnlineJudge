var
        n,k:longint;
function find(n,k,s:longint):longint;
var sum,i:longint;
begin
        sum:=0;
        if k=1 then exit(1);
        for i:=s to n div k do
                sum:=sum+find(n-i,k-1,i);
        exit(sum);
end;
begin
        readln(n,k);
        writeln(find(n,k,1));
end.