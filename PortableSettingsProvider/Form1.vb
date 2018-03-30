Public Class Form1

    Private Sub Form1_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load

        Me.Location = My.Settings.WindowLocation
        Me.ClientSize = My.Settings.WindowSize

        Me.TextBox1.Text = My.Settings.UserWord

    End Sub

    Private Sub Form1_FormClosing(ByVal sender As Object, ByVal e As System.Windows.Forms.FormClosingEventArgs) Handles Me.FormClosing
        If Me.WindowState = FormWindowState.Normal Then
            My.Settings.WindowLocation = Me.Location
            My.Settings.WindowSize = Me.ClientSize
        End If

        My.Settings.UserWord = Me.TextBox1.Text
    End Sub
End Class