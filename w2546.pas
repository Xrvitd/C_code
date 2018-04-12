program w2546(input,output);
var a,b,cc,c,dd:array[-10..10000] of longint;
    me:array[-10..5000]of boolean;    //true:odd; false:even;
    d,fa:array[-10..20000]of longint;
    n,max:longint;

procedure sort(p,q,r:longint);
  var tl,tr,tt:longint;
  begin
    tl:=p; tr:=q+1; tt:=p;
    while tt<=r do
      if (tl<=q)and ((tr>r)or(c[tl]<=c[tr])) then
        begin
          cc[tt]:=c[tl];
          dd[tt]:=d[tl];
          inc(tt); inc(tl);
        end
      else
        begin
          cc[tt]:=c[tr];
          dd[tt]:=d[tr];
          inc(tt); inc(tr);
        end;

    for tt:=p to r do
      begin
        c[tt]:=cc[tt];
        d[tt]:=dd[tt];
      end;
  end;

procedure merge(p,r:longint);
  var q:longint;
  begin
    if p<r then
      begin
        q:=(p+r-1) shr 1;
        merge(p,q);
        merge(q+1,r);
        sort(p,q,r);
      end;
  end;

procedure init;
  var i,j:longint;
      ch:char;
  begin
    readln(n);
    readln(n);
    for i:=1 to n do
      begin
        read(a[i],b[i]);
        read(ch);
        readln(ch);
        if ch='e' then me[i]:=false
        else me[i]:=true;
      end;

    for i:=1 to n do
      begin
        c[i]:=a[i];
        c[i+n]:=b[i];
        d[i]:=i;
        d[i+n]:=i+n;
      end;

    merge(1,2*n);
    max:=0;
    c[0]:=-1;
    for i:=1 to 2*n do
      if c[i]<>c[i-1] then
        begin
          if c[i]-c[i-1]=1 then inc(max) else inc(max,2);
          cc[i]:=max;
        end
      else cc[i]:=cc[i-1];


      for i:=1 to 2*n do
      c[d[i]]:=cc[i];
    for i:=1 to n do
      begin
        a[i]:=c[i];
        b[i]:=c[i+n];
      end;

    for i:=-10 to max do fa[i]:=i;
  end;

function getfather(k:longint):longint;
  var t:longint;
  begin
    if fa[k]=k then exit(k);
    t:=getfather(fa[k]);
    d[k]:=d[k] xor d[fa[k]];
    fa[k]:=t;
    exit(t);
  end;

procedure work;
  var p,q,i,j,k:longint;

  procedure outit;
    begin
      writeln(k-1);
      halt;
    end;

  begin
    fillchar(d,sizeof(d),0);
    for k:=1 to n do
        if me[k] then
          begin    // odd;
            p:=getfather(a[k]-1);
            q:=getfather(b[k]);
            if (p=q)and(d[a[k]-1]=d[b[k]]) then outit;
            if p<>q then
              begin
                if d[a[k]-1] xor d[b[k]]=0  then
                  begin
                    fa[q]:=p;
                    d[q]:=1;
                  end;
                if d[a[k]-1] xor d[b[k]]=1 then fa[q]:=p;
              end;
          end
        else
          begin     // even;
            p:=getfather(a[k]-1);
            q:=getfather(b[k]);
            if (p=q)and(d[a[k]-1]<>d[b[k]]) then outit;
            if p<>q then
              begin
                if d[a[k]-1] xor d[b[k]]=0 then fa[q]:=p;
                if d[a[k]-1] xor d[b[k]]=1 then
                  begin
                    fa[q]:=p;
                    d[q]:=1;
                  end;
              end;
          end;
  end;

begin
  init;           //complete;
  work;
  writeln(n);
end.
