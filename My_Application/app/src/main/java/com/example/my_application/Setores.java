package com.example.my_application;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import androidx.appcompat.app.AppCompatActivity;

public class Setores extends AppCompatActivity {

    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.setores);
    }

    public void irSala(View view) {
        Intent startNewActivity = new Intent(Setores.this, Salas.class);
        startActivityForResult(startNewActivity, 1);
    }

}
