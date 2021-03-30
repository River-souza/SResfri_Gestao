package com.example.my_application;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.app.AlertDialog;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    private EditText edtUsuario;
    private EditText edtSenha;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        InicializaObjetos();
    }

    public void InicializaObjetos()
    {
        edtUsuario = (EditText) findViewById(R.id.edtUsuario);
        edtSenha = (EditText) findViewById(R.id.edtSenha);
    }

    private void MensagemInformativa(String mensagen) {
        new AlertDialog.Builder(this)
                .setTitle("Informativo")
                .setMessage(mensagen)
                .setPositiveButton("OK", null)
                .setCancelable(false)
                .show();
    }


    public void login(View view) {
        Login login = new Login();
        login.setUsuario(edtUsuario.getText().toString());
        login.setSenha(edtSenha.getText().toString());

        if (login.ValidarUsuario() == false)
        {
            this.MensagemInformativa("Dados Incorretos!");

            edtSenha = (EditText) findViewById(R.id.edtSenha);

            edtUsuario.setText("");
            edtSenha.setText("");
        }
        else
        {
            Intent startNewActivity = new Intent(MainActivity.this, Setores.class);
            startActivityForResult(startNewActivity, 1);
        }
    }

}



