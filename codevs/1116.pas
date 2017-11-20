program ysh(input,output);
var
  n,i,j,ans:longint;
  a:array[1..20] of longint;
  v:array[1..20,1..20] of longint;
procedure search(i:longint);
var
  j,k:longint;
  flag:boolean;
begin
  if i=n+1 then
    begin
      inc(ans);
      exit;
    end;
  for j:=1 to 4 do
    begin
      flag:=true;
      for k:=1 to i do
        if (v[i,k]=1)and(j=a[k]) then flag:=false;
      if flag then
        begin
          a[i]:=j;
          search(i+1);
        end;
    end;
end;
begin
  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to n do read(v[i,j]);
      readln;
    end;
  ans:=0;
  search(1);
  writeln(ans);
end.