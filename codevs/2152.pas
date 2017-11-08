const
  dx:array[1..4] of integer=(-1,0,0,1);
  dy:array[1..4] of integer=(0,1,-1,0);
var
  r,c,i,j,max:longint;
  a,f:array[1..100,1..100] of longint;
function  dfs( x,y:longint ):longint;
var
  i,nx,ny,max:integer;
begin
  if f[x,y]<>0 then exit(f[x,y]);
  max:=0;
  for i:=1 to 4 do
  begin
    nx:=x+dx[i];
    ny:=y+dy[i];
    if (nx > 0) and (nx <= r) and (ny > 0) and (ny <= c) then
      if a[x,y] > a[nx,ny] then
        if dfs(nx,ny) > max then
          max:=dfs(nx,ny);
  end;
  dfs:=max+1;
  f[x,y]:=dfs;
end;
begin
  readln(r,c);
  for i:=1 to r do
    for j:=1 to c do
      read(a[i,j]);
  fillchar(f,sizeof(f),0);
  max:=-maxint;
  for i:=1 to r do
    for j:=1 to c do
      if dfs(i,j) > max then
    max:=dfs(i,j);
  writeln(max);
end.