package com.example.my_application;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import androidx.appcompat.app.AppCompatActivity;

public class Salas extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.salas);
    }

    public void irCondicionador(View view) {
        Intent startNewActivity = new Intent(Salas.this, Condicionador.class);
        startActivityForResult(startNewActivity, 1);
    }
}
