@ModelType IndexViewModel
@Code
    ViewBag.Title = "管理"
End Code

<h2>@ViewBag.Title.</h2>

<p class="text-success">@ViewBag.StatusMessage</p>
<div>
    <h4>更改你的帐户设置</h4>
    <hr />
    <dl class="dl-horizontal">
        <dt>密码:</dt>
        <dd>
            [
            @If Model.HasPassword Then
                @Html.ActionLink("更改密码", "ChangePassword")
            Else
                @Html.ActionLink("创建", "SetPassword")
            End If
            ]
        </dd>
        <dt>外部登录名:</dt>
        <dd>
            @Model.Logins.Count [
            @Html.ActionLink("管理", "ManageLogins") ]
        </dd>
        @*
            电话号码可以用作双因素身份验证系统中的第二个验证因素。
             
             要详细了解如何设置此 ASP.NET 应用程序以支持使用
                SMS 进行双因素身份验证，请参阅<a href="https://go.microsoft.com/fwlink/?LinkId=403804">此文章</a>。
             
             设置双因素身份验证后，取消注释以下块
        *@
        @* 
            <dt>电话号码:</dt>
            <dd>
                @(If(Model.PhoneNumber, "None"))
                @If (Model.PhoneNumber <> Nothing) Then
                    @<br />
                    @<text>[&nbsp;&nbsp;@Html.ActionLink("Change", "AddPhoneNumber")&nbsp;&nbsp;]</text>
                    @Using Html.BeginForm("RemovePhoneNumber", "Manage", FormMethod.Post, New With {.class = "form-horizontal", .role = "form"})
                        @Html.AntiForgeryToken
                        @<text>[<input type="submit" value="删除" class="btn-link" />]</text>
                    End Using
                Else
                    @<text>[&nbsp;&nbsp;@Html.ActionLink("Add", "AddPhoneNumber") &nbsp;&nbsp;]</text>
                End If
            </dd>
        *@
        <dt>双重身份验证:</dt>
        <dd>
            <p>
                未配置双因素身份验证提供程序。请参阅<a href="https://go.microsoft.com/fwlink/?LinkId=403804">此文章</a>
                详细了解如何设置此 ASP.NET 应用程序以支持双因素身份验证。
            </p>
            @*
                @If Model.TwoFactor Then
                    @Using Html.BeginForm("DisableTwoFactorAuthentication", "Manage", FormMethod.Post, New With { .class = "form-horizontal", .role = "form" })
                      @Html.AntiForgeryToken()
                      @<text>
                      已启用
                      <input type="submit" value="禁用" class="btn btn-link" />
                      </text>
                    End Using
                Else
                    @Using Html.BeginForm("EnableTwoFactorAuthentication", "Manage", FormMethod.Post, New With { .class = "form-horizontal", .role = "form" })
                      @Html.AntiForgeryToken()
                      @<text>
                      已禁用
                      <input type="submit" value="启用" class="btn btn-link" />
                      </text>
                    End Using
                End If
	     *@
        </dd>
    </dl>
</div>
