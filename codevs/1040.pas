const
  maxle=202;
  maxk=40;
  maxs=6;
type
  strr=string[maxle];
var
  f:array[0..maxle,0..maxk]of integer;
  g:array[0..maxle,0..maxle]of integer;
  d:array[1..maxle]of integer;
  w:array[1..maxs]of strr;
  s:strr;
  i,j,n,p,k,le,ans:integer;

procedure makearrd;
  var
    i,j:integer;
  begin
    fillchar(d,sizeof(d),$4f);
    for i:=1 to le do
      for j:=1 to p do
        if (pos(w[j],copy(s,i,length(w[j])+i-1))=1)and(d[i]>length(w[j]))
          then d[i]:=length(w[j]);
  end;
procedure makearrg;
  var
    i,j,t:integer;
  begin
    fillchar(g,sizeof(g),0);
    for i:=1 to le do
      for j:=1 to le do
        for t:=i to j do
          if t+d[t]-1<=j then inc(g[i,j]);
  end;
procedure main;
  var
    i,j,t:integer;
  begin
    makearrd;
    makearrg;
    fillchar(f,sizeof(f),0);
   for j:=1 to k do
      for i:=j to le do
        for t:=i to le do
          if f[i-1,j-1]+g[i,t]>f[t,j] then f[t,j]:=f[i-1,j-1]+g[i,t];
  end;
procedure init;
  var
    i:integer;
    t:strr;
  begin
    readln(p,k);
    s:='';
    for i:=1 to p do
      begin
        readln(t);
        s:=s+t;
      end;
    le:=20*p;
    readln(p);
    for i:=1 to p do readln(w[i]);
  end;
begin
  readln(n);
  for i:=1 to n do
    begin
      init;
      main;
      writeln(f[le,k]);
    end;
end.