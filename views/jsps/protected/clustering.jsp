		<table border="0" width="100%" cellpadding="0">
			<tr>
				<td width="84%" valign="top">
					<table width="100%" bgcolor="#c0c0c0">
						<tr bgcolor="#707070">
							<td width="90%">
								<table cellpadding="0" cellspacing="0">
									<tr>
										<td>&nbsp;&nbsp;<STRONG><a href="<c:url value="/protected/enhancer.do"/>" id="sbsHeaderLink">Super Enhancer</a></td>
										<td>&nbsp;&nbsp;<font color="#ffffff" face="Arial" size="2"><STRONG>&nbsp;|&nbsp</STRONG></FONT></td>
										<td>&nbsp;&nbsp;<FONT face="Arial" color="#ff0000" size="2"><strong>Super Cluster</strong></td>
									</tr>
								</table>
							</td>
							<td width="10%" align="right"><a href="/BugTrack/jsps/helpJsp"><STRONG><font color="#ffffff" face="Arial" size="2">Help?</STRONG></FONT></a></td>
						</tr>
					</table>
				</td>
			</tr>
		</table>

		<table border="0" width="100%" cellpadding="0">
			<tr>
				<td width="84%" valign="top">
					<table width="100%" bgcolor="#c0c0c0">
						<tr>
							<td bgcolor="lightgrey">
								<DIV style="WIDTH: 680px; POSITION: relative; HEIGHT: 528px" ms_positioning="GridLayout"><INPUT id="Button1" style="Z-INDEX: 101; LEFT: 608px; WIDTH: 56px; POSITION: absolute; TOP: 488px; HEIGHT: 24px"
										type="button" value="Help" name="helpBtn"><INPUT language="javascript" id="Reset1" style="Z-INDEX: 102; LEFT: 536px; WIDTH: 60px; POSITION: absolute; TOP: 488px; HEIGHT: 24px"
										onclick="return Reset1_onclick()" type="reset" value="Reset" name="Reset1"><INPUT id="Submit1" style="Z-INDEX: 103; LEFT: 464px; POSITION: absolute; TOP: 488px" type="submit"
										value="Search" name="Submit1">
									<HR style="Z-INDEX: 104; LEFT: 0px; POSITION: absolute; TOP: 480px" width="100%" SIZE="1">
									<HR style="Z-INDEX: 105; LEFT: 0px; POSITION: absolute; TOP: 48px" width="100%" SIZE="1">
									<DIV id="DIV1" style="DISPLAY: inline; Z-INDEX: 106; LEFT: 0px; WIDTH: 112px; POSITION: absolute; TOP: 16px; HEIGHT: 24px"
										align="right" ms_positioning="FlowLayout" language="javascript" onclick="return DIV1_onclick()"><b><font face="Arial" size="2">Search 
												Criteria:</font></b></DIV>
									<INPUT id="File1" style="Z-INDEX: 107; LEFT: 120px; WIDTH: 352px; POSITION: absolute; TOP: 16px; HEIGHT: 22px"
										type="file" size="39" name="File1"> <INPUT language="javascript" id="loadSaveBtn" style="Z-INDEX: 108; LEFT: 512px; WIDTH: 152px; POSITION: absolute; TOP: 16px; HEIGHT: 24px"
										onclick="return loadSaveBtn_onclick()" type="button" value="Load/Save Criteria" name="Button2">
									<SELECT id="organismDD" style="Z-INDEX: 109; LEFT: 120px; WIDTH: 272px; POSITION: absolute; TOP: 56px"
										name="organizmDD">
										<option value=dromel selected>Drosophila melanogaster</option>
										<option value=anogam>Anopheles gambiae</option>
										<option value=cioint>Ciona intestinalis</option>
										<option value=ciosav>Ciona savignyi</option>
										<option value=fugu>Fugu</option>
										<option value=apimel>Apis mellifera</option>

									</SELECT>
									<DIV style="DISPLAY: inline; Z-INDEX: 110; LEFT: 32px; WIDTH: 80px; POSITION: absolute; TOP: 56px; HEIGHT: 16px"
										align="right" ms_positioning="FlowLayout"><b><font face="Arial" size="2">Organism:<b></font></DIV>
									<TABLE id="Table2" style="Z-INDEX: 111; LEFT: 32px; WIDTH: 360px; FONT-FAMILY: Arial; POSITION: absolute; TOP: 88px; HEIGHT: 144pxBORDER-RIGHT: white thin solid; BORDER-TOP: white thin solid; BORDER-LEFT: white thin solid; BORDER-BOTTOM: white thin solid;"
										cellSpacing="1" cellPadding="1" width="180">
										<thead style="COLOR: #ffffff" bgColor="#005099">
											<tr>
												<th>
													Name</th>
												<th>
													Search Criteria</th>
												<th>
													Overlap</th></tr>
										</thead>
										<TR>
											<TD title="Name" style="WIDTH: 43px" align="center">A</TD>
											<TD style="WIDTH: 239px"><SELECT id="Select1" style="WIDTH: 240px; HEIGHT: 22px" name="Select1"><option selected></option>
												</SELECT></TD>
											<TD align="center"><INPUT id="Checkbox1" type="checkbox" name="Checkbox1"></TD>
										</TR>
										<TR>
											<TD title="Name" style="WIDTH: 43px" align="center" bgColor="gainsboro">B</TD>
											<TD style="WIDTH: 239px" bgColor="gainsboro"><SELECT id="Select2" style="WIDTH: 240px; HEIGHT: 22px" NAME="Select2"><option selected></option>
												</SELECT></TD>
											<TD align="center" bgColor="gainsboro"><INPUT id="Checkbox2" type="checkbox" name="Checkbox1"></TD>
										</TR>
										<TR>
											<TD title="Name" style="WIDTH: 43px" align="center">C</TD>
											<TD style="WIDTH: 239px"><SELECT id="Select3" style="WIDTH: 240px; HEIGHT: 22px" NAME="Select3"><option selected></option>
												</SELECT></TD>
											<TD align="center"><INPUT id="Checkbox3" type="checkbox" name="Checkbox1"></TD>
										</TR>
										<TR>
											<TD title="Name" style="WIDTH: 43px" align="center" bgColor="gainsboro">D</TD>
											<TD style="WIDTH: 239px" bgColor="gainsboro"><SELECT id="Select4" style="WIDTH: 240px; HEIGHT: 22px" NAME="Select4"><option selected></option>
												</SELECT></TD>
											<TD align="center" bgColor="gainsboro"><INPUT id="Checkbox4" type="checkbox" name="Checkbox1"></TD>
										</TR>
										<TR>
											<TD title="Name" style="WIDTH: 43px" align="center">E</TD>
											<TD style="WIDTH: 239px"><SELECT id="Select5" style="WIDTH: 240px; HEIGHT: 22px" NAME="Select5"><option selected></option>
												</SELECT></TD>
											<TD align="center"><INPUT id="Checkbox5" type="checkbox" name="Checkbox1"></TD>
										</TR>
										<TR>
											<TD title="Name" style="WIDTH: 43px" align="center" bgColor="gainsboro">F</TD>
											<TD style="WIDTH: 239px" bgColor="gainsboro"><SELECT id="Select6" style="WIDTH: 240px; HEIGHT: 22px" NAME="Select6"><option selected></option>
												</SELECT></TD>
											<TD align="center" bgColor="gainsboro"><INPUT id="Checkbox6" type="checkbox" name="Checkbox1"></TD>
										</TR>
										<TR style="FONT-FAMILY: Arial">
											<TD title="Name" style="WIDTH: 43px" align="center">G</TD>
											<TD style="WIDTH: 239px"><SELECT id="Select7" style="WIDTH: 240px; HEIGHT: 22px" NAME="Select7"><option selected></option>
												</SELECT></TD>
											<TD align="center"><INPUT id="Checkbox7" type="checkbox" name="Checkbox1"></TD>
										</TR>
										<TR>
											<TD title="Name" style="WIDTH: 43px" align="center" bgColor="gainsboro">H</TD>
											<TD style="WIDTH: 239px" bgColor="gainsboro"><SELECT id="Select8" style="WIDTH: 240px; HEIGHT: 22px" NAME="Select8"><option selected></option>
												</SELECT></TD>
											<TD align="center" bgColor="gainsboro"><INPUT id="Checkbox8" type="checkbox" name="Checkbox1"></TD>
										</TR>
										<TR>
											<TD title="Name" style="WIDTH: 43px" align="center">I</TD>
											<TD style="WIDTH: 239px"><SELECT id="Select9" style="WIDTH: 240px; HEIGHT: 22px" NAME="Select9"><option selected></option>
												</SELECT></TD>
											<TD align="center"><INPUT id="Checkbox9" type="checkbox" name="Checkbox1"></TD>
										</TR>
										<TR>
											<TD title="Name" style="WIDTH: 43px" align="center" bgColor="gainsboro">J</TD>
											<TD style="WIDTH: 239px" bgColor="gainsboro"><SELECT id="Select10" style="WIDTH: 240px; HEIGHT: 22px" NAME="Select10"><option selected></option>
												</SELECT></TD>
											<TD align="center" bgColor="gainsboro"><INPUT id="Checkbox10" type="checkbox" name="Checkbox1"></TD>
										</TR>
									</TABLE>
									<HR style="Z-INDEX: 112; LEFT: 0px; WIDTH: 99.81%; POSITION: absolute; TOP: 520px; HEIGHT: 1px"
										width="99.81%" SIZE="1">
									<TABLE id="Table3" style="Z-INDEX: 113; LEFT: 408px; WIDTH: 264px; FONT-FAMILY: Arial; POSITION: absolute; TOP: 80px; HEIGHT: 88px"
										cellSpacing="1" cellPadding="1" width="264" border="0">
										<TR>
											<TD style="WIDTH: 137px; HEIGHT: 29px" align="right"><b>Number of Sites:</b></TD>
											<TD style="HEIGHT: 29px"><INPUT language="javascript" id="Text11" style="WIDTH: 120px; HEIGHT: 22px" onclick="return Text11_onclick()"
													type="text" size="14" name="sites" value="3"></TD>
										</TR>
										<TR>
											<TD style="WIDTH: 137px; HEIGHT: 26px" align="right"><b>Overlap Sites:</b></TD>
											<TD style="HEIGHT: 26px"><INPUT id="Text12" style="WIDTH: 120px; HEIGHT: 22px" type="text" size="14" name="Text11"></TD>
										</TR>
										<TR>
											<TD style="WIDTH: 137px" align="right"><b>Width:</b></TD>
											<TD><INPUT id="Text13" style="WIDTH: 120px; HEIGHT: 22px" type="text" size="14" name="constraint" value="5000"></TD>
										</TR>
										<tr>
											<td><table>
												<tr>
													<td><strong>Min</strong></td><td><input type="text" name="min" size="10"/></td>
												</tr>
											</table>
											</td>
											<td><table>
												<tr>
													<td><strong>Max</strong></td><td><input type="text" name="max" size="10"/></td>
												</tr>
											</table>
											</td>

										</tr>-
									</TABLE>
									<TABLE id="Table4" style="Z-INDEX: 114; LEFT: 416px; WIDTH: 259px; FONT-FAMILY: Arial; POSITION: absolute; TOP: 220px; HEIGHT: 108px"
										cellSpacing="0" cellPadding="1" width="259" border="0">
										<TR>
											<TD style="HEIGHT: 23px"><STRONG>Condition:</STRONG></TD>
										</TR>
										<TR>
											<TD style="HEIGHT: 54px" vAlign="top" align="left"><TEXTAREA id="Textarea1" style="WIDTH: 256px; HEIGHT: 44px" name="boolean" rows="4"cols="29"></TEXTAREA></TD>
										</TR>
										<TR>
											<TD style="HEIGHT: 23px"><STRONG>Order of Sites:</STRONG></TD>
										</TR>
										<TR>
											<TD vAlign="top" align="left" style="HEIGHT: 54px"><TEXTAREA id="Textarea2" style="WIDTH: 256px; HEIGHT: 44px" name="precedence" rows="4" cols="29"></TEXTAREA></TD>
										</TR>
										<tr>
											<td>
												<DIV style="DISPLAY: inline; WIDTH: 96px; HEIGHT: 24px" ms_positioning="FlowLayout"><b>Use 
														Cache</b></DIV>
												<INPUT id="Checkbox11" type="checkbox" name="cache" CHECKED></td>
										</tr>
									</TABLE>
									<TABLE id="Table5" style="Z-INDEX: 115; LEFT: 32px; WIDTH: 640px; POSITION: absolute; TOP: 416px; HEIGHT: 56px"
										cellSpacing="0" cellPadding="1" width="640" border="0">
										<TR>
											<TD style="WIDTH: 199px; HEIGHT: 23px" align="right"><STRONG><FONT face="Arial">Width to 
														Include:</FONT></STRONG></TD>
											<TD style="WIDTH: 155px; HEIGHT: 23px"><INPUT id="Text14" type="text" name="display" value="20000" style="WIDTH: 154px; HEIGHT: 22px" size="20"></TD>
											<TD style="WIDTH: 85px; HEIGHT: 23px" align="right"><STRONG><font face="Arial">Genes:</font></STRONG></TD>
											<TD style="WIDTH: 174px; HEIGHT: 23px">
												<INPUT id="RadioWest" type="radio" value="West" name="RadioGroup"><font face="Arial">West</font><INPUT id="RadioEast" type="radio" value="East" name="RadioGroup"><font face="Arial">East</font>
												<INPUT id="RadioBoth" type="radio" CHECKED value="Both" name="RadioGroup"><font face="Arial">Both</font>
											</TD>
										</TR>
										<TR>
											<TD style="WIDTH: 199px" align="right"><FONT face="Arial"><STRONG>Gene Names</STRONG><FONT size="2">(separated 
														by ;)</FONT><STRONG>: </STRONG></FONT>
											</TD>
											<TD style="WIDTH: 155px"><INPUT id="Text15" style="WIDTH: 154px; HEIGHT: 22px" type="text" size="20" name="Text14"></TD>
											<TD style="WIDTH: 85px" align="right"><STRONG><FONT face="Arial">Any Gene:</FONT></STRONG></TD>
											<TD style="WIDTH: 174px"><INPUT id="Checkbox12" type="checkbox" name="Checkbox12"></TD>
										</TR>
									</TABLE>
								</DIV>
								</B></B>
							</td>
						</tr>
					</table>
				</td>
			</tr>
		</table>
	</body>
</html>
