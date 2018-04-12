program w1069(input,output);
var f,d:array[0..20000]of longint;
    w,a,b,ww,aa,bb:array[0..100000]of longint;
    n,m,i:longint;

function getfather(k:longint):longint;
  begin
    if f[k]=k then exit(k);
    exit(getfather(f[k]));
  end;

function path(k:Longint):longint;
  var length,p:longint;
  begin
    length:=0;
    if f[k]=k then exit(0);
    p:=k;
    while f[f[p]]<>f[p] do
      begin
        inc(length);
        p:=f[p];
      end;
    if length and 1=1 then
      begin
        f[k]:=p;
        exit(0);
      end;

    f[k]:=f[p];
    exit(1);
  end;

procedure union(i,j,k:Longint);
  var p,q,x,y:longint;
  begin
    p:=getfather(i);
    q:=getfather(j);
    x:=path(i);
    y:=path(j);
    if p=q then
      if x=y then
        begin
          write(w[k]);
          halt;
        end;

    if x=y then f[q]:=p
    else if p<>q then
      begin
        if x<y then f[p]:=j;
        if x>y then f[q]:=i;
      end;
  end;

procedure init;
  var i:longint;
  begin
    readln(n,m);
    for i:=1 to m do
      begin
        read(a[i],b[i]);
        read(w[i]);
      end;
    for i:=1 to n do
      begin
        f[i]:=i;
        d[i]:=1;
      end;
  end;

procedure sort(p,q,r:longint);
  var tl,tr,tt:longint;
  begin
    tl:=p; tt:=p; tr:=q+1;
    while tt<=r do
     if (tl<=q)and((tr>r)or(w[tl]>w[tr])) then
       begin
         ww[tt]:=w[tl];
         aa[tt]:=a[tl];
         bb[tt]:=b[tl];
         inc(tt); inc(tl);
       end
     else
       begin
         ww[tt]:=w[tr];
         aa[tt]:=a[tr];
         bb[tt]:=b[tr];
         inc(tt); inc(tr);
       end;

    for tt:=p to r do
      begin
        a[tt]:=aa[tt];
        b[tt]:=bb[tt];
        w[tt]:=ww[tt];
      end;
  end;

procedure merge(p,r:longint);
  var q:longint;
  begin
    if p<>r then
      begin
        q:=(p+r-1) shr 1;
        merge(p,q);
        merge(q+1,r);
        sort(p,q,r);
      end;
  end;

begin
  init;
  merge(1,m);
  for i:=1 to m do union(a[i],b[i],i);
  writeln(0);
end.
