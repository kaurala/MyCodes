#!c:\python27\python.exe

print 'Content-type: text/html\n'

import cgitb
cgitb.enable()

import MySQLdb
conn=MySQLdb.connect(host='localhost',user='root',passwd='Dyc19930418',
		port=3306,db='pythonsql')
curs=conn.cursor()

import cgi,sys
form=cgi.FieldStorage()
reply_to=form.getvalue('reply_to')

print """
<html>
 <head>
  <title>Compose Message</title>
 </head>
 <body>
  <h1>Compose Message</h1>

  <form action='save.cgi' method='POST'>
  """

subject=''
if reply_to is not None:
	print '<input type="hidden" name="reply_to" value="%s"/>' % reply_to
	curs.execute('select subject from messages where id=%s' %reply_to)
	subject=curs.fetchone()[0]
	if not subject.startswith('Re: '):
		subject='Re: '+subject

print """
	<b>Subject:</b><br />
	<input type='text' size='40' name='subject' value='%s' />
	<br />
	<b>Sender:</b><br />
	<input type='text' size='40' name='sender' />
	<br />
	<b>Message:</b><br />
	<textarea name='text' cols='40' rows='20'></textarea>
	<br />
	<input type='submit' value='Save' />
	</form>
	<hr />
	<a href='main.cgi'>Back to the main page</a>
	</body>
</html>
""" % subject
	
