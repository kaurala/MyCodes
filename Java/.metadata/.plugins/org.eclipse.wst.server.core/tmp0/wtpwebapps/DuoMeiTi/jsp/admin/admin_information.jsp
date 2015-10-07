<%@ include file="/jsp/base/taglib.jsp" %>


<layout:override name="main_content">
	<div class="mycontent">
		<br/>
		
		
		<form class="form-inline"  method="POST" id="admin_information_form">
		
		
			<br>
			<br>
			<br>
			<br>
			
		 	<div class="form-group col-lg-offset-1">
		    	<label for="username">用&nbsp;&nbsp;户&nbsp;&nbsp;名:</label>
		 		<input type="text" class="form-control" id="username" name="username" value=<s:property value="#session.username"/> placeholder=<s:property value="#session.username"/> readonly>
			</div>
			<div class="form-group col-lg-offset-1">
		    	<label for="fullName">姓&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;名:</label>
		 		<input type="text" class="form-control" id="fullName" name="fullName" value=<s:property value="fullName"/> >
			</div>
			<br>
			<br>
			<br>
			
			<div class="form-group col-lg-offset-1">
		    	<label for="phoneNumber">联系方式:</label>
		    	<input type="text" class="form-control"  id="phoneNumber" name="phoneNumber" value=<s:property value="phoneNumber"/> >
			</div>
			<div class="form-group col-lg-offset-1">
				<label for="sex">性&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;别:</label>
			  	<s:select list="sexSelect" class="form-control" name="sex" id="sex" onblur="checkSex()" ></s:select>
			</div>  
			<br>
			<br>
			<br>
			
			<div class="form-group col-lg-offset-1">
				<label for="unitInfo">工作单位:</label> 
				<input type="text" class="form-control" name="unitInfo" value="<s:property value="unitInfo"/>" placeholder=<s:property value="unitInfo"/>>
			</div>
			<div class="form-group col-lg-offset-1">
				<label for="remark">备&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;注:</label>
				<input type="text" class="form-control" name="remark" value="<s:property value="remark"/>" placeholder=<s:property value="remark"/>>
			</div>
			
			<br>
			<br>
			<br>
			
		
			<button type="button" class="btn btn-success col-lg-offset-5" id="change">修改</button>
		  
		</form>
		
		
		
		<script>
		
		$(document).on('click',"#change",function(){
			var params = $('#admin_information_form').serialize(); //利用jquery将表单序列化 
	        $.ajax({
	          url: 'admin_information_change',
	          type: 'post',
	          dataType: 'json',
	          data: params,
	          success: adminRegisterCallback
	        });
			
		})
		
		function adminRegisterCallback(data)
	    {    	
			alert("changed");

	    }	
		
		</script>
		
		
	</div>
</layout:override>



<%@ include file="/jsp/admin/base.jsp" %>